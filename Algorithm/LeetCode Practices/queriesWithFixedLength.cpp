/**
 * @file queriesWithFixedLength.cpp
 * @author Ivan Jonathan
 * @brief Problem: https://www.hackerrank.com/challenges/queries-with-fixed-length/problem
 * @version 0.1
 * @date 2022-02-07
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int solveUtil(const vector<int> &arr, int d) {
    int size = arr.size();
    int min = INT_MAX;
    
    deque<int> dq;
    
    if (d == 1) {
        // if d is 1, we just need to check minimum value of given array
        return *min_element(arr.begin(), arr.end());
    } else { // d > 1

        // Suppose, we have array like this:
        // [33, 11, 44, 11, 55]
        //
        // d = 2
        // i = 0
        // dq = [0]
        //
        // i = 1
        // dq = [0, 1]
        for (int i = 0; i < d; i++) {
            while (!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
        }
        
        // - 1st element always be max element of subarray [arr[0] ... arr[d-1]]
        min = arr[dq.front()];
        
        for (int i = d; i < arr.size(); i++) {
            while (!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
            
            if (dq.front() == i - d) {
                dq.pop_front();
            }
            
            min = std::min(min, arr[dq.front()]);

            // int max = *max_element(v.begin(), v.end());
            // if (min > max) {
            //     min = max;
            // }
        }
    }
    
    return min;
}

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY queries
 */
vector<int> solve(vector<int> arr, vector<int> queries) {
    vector<int> res;
    
    for (int q : queries) {
        res.push_back(solveUtil(arr, q));
    }
    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> queries(q);

    for (int i = 0; i < q; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = solve(arr, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}