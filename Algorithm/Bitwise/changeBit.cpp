#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int transformToBin(string s) {
    int i = s.size() - 1;
    int j = 0;
    
    int result = 0;
    while (i >= 0) {
        char c = s[i--];
        if (c == '1') {
            result = result | (1 << j);
        }
        
        j++;
    }
    
    return result;
}

int toInteger(string s) {
    int num = 0;
    int j = s.size() - 1;
    
    while (j >= 0) {
        num = num * 10 + ((s[j] - '0') % 10);
        j--;
    }
    
    return num;
}

void changeBits(string a, string b, vector<string> queries) {
    int aInt = transformToBin(a);
    int bInt = transformToBin(b);
    int cInt = 0;
    
    for (string query : queries) {
        stringstream ss(query);
        string word;
        vector<string> splitted;
        
        while (ss >> word) {
            splitted.push_back(word);
        }
        
        string operation = splitted[0];
        int idx = toInteger(splitted[1]);
        
        if (operation == "set_a") {
            string value = splitted[2];
            int intValue = toInteger(value) << idx;
            
            if (intValue == 1) {
                aInt = aInt | intValue;
            } else {
                aInt = aInt & intValue;
            }
        } else if (operation == "set_b") {
            string value = splitted[2];
            int intValue = toInteger(value) << idx;
            
            if (intValue == 1) {
                bInt = bInt | intValue;
            } else {
                bInt = bInt & intValue;
            }
        } else {
            cInt = aInt + bInt;
            while (idx > 0) {
                cInt = cInt >> 1;
                idx--;
            }
            
            cout << (cInt & 1);
        }
    }
}