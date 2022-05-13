'use strict';

const fs = require('fs');
const https = require('https');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function(inputStdin) {
    inputString += inputStdin;
});

process.stdin.on('end', function() {
    inputString = inputString.split('\n');

    main();
});

function readLine() {
    return inputString[currentLine++];
}

const getUrl = (year, page) => {
    return `https://jsonmock.hackerrank.com/api/football_matches?competition=UEFA%20Champions%20League&year=${year}&page=${page}`;
};

const fetch = (url) => {
   return new Promise((resolve, reject) => {
    https
      .get(url, (resp) => {
        let data = '';
        
        // receiving chunk...
        resp.on('data', (chunk) => {
            data += chunk;
        });
        
        // when the whole response hsa been received
        resp.on('end', () => {
            resolve(JSON.parse(data));
        })
      })
      .on('error', (err) => {
          reject(err);
      });
   });
};


async function getTeams(year, k) {
    // write your code here
    // API endpoint template: https://jsonmock.hackerrank.com/api/football_matches?competition=UEFA%20Champions%20League&year=<YEAR>&page=<PAGE_NUMBER>

    const res = {};
    
    let initialPage = 1;
    let totalPage = 1;
    
    while (initialPage <= totalPage) {
        const { total_pages, data } = await new Promise((resolve, reject) => {
            fetch(getUrl(year, initialPage))
                .then(jsonResponse => resolve(jsonResponse))
                .catch(err => {
                    console.log(err);
                    reject(err);
                }) 
        });
        
        data.forEach(({ team1, team2 }) => {
            res[team1] = (res[team1] || 0) + 1;
            res[team2] = (res[team2] || 0) + 1;
        });
        
        totalPage = total_pages;
        initialPage++;
    }
    
    return Object.entries(res)
        .filter(([, numOfMatches]) => numOfMatches >= k)
        .map(([team,]) => team)
        .sort();
}

async function main() {
  const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

  const year = parseInt(readLine().trim());
  const k = parseInt(readLine().trim());

  const teams = await getTeams(year, k);

  for (const team of teams) {
    ws.write(`${team}\n`);
  }
}
