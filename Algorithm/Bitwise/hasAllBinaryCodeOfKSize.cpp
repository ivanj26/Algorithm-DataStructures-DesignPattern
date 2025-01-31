#include <string>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
// Example 1:

// Input: s = "00110110", k = 2
// Output: true
// Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
// Example 2:

// Input: s = "0110", k = 1
// Output: true
// Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
// Example 3:

// Input: s = "0110", k = 2
// Output: false
// Explanation: The binary code "00" is of length 2 and does not exist in the array.

class Solution {
    private:
        bool isSubstring(string &s, string &b) {
            for (int i = 0; i < s.length(); i++) {
                if (s.substr(i, b.length()) == b) {
                    return true;
                }
            }

            return false;
        }
    public:
        bool hasAllCodes(string s, int k) {
            int end = 1 << k;
            int length = log2(end);

            vector<string> allSubs;
            for (int i = 0; i < end; i++) {
                string b(length, '0');
                
                int curr = i;
                int j = 0;
                while (curr > 0) {
                    int lsb = curr & 1;
                    if (lsb == 1) {
                        b[j] = '1';
                    }
                    
                    curr >>= 1;
                    j++;
                }

                allSubs.push_back(b);
            }

            for (string sub: allSubs) {
                if (!isSubstring(s, sub)) {
                    return false;
                }
            }

            return true;
        }
};

int main() {
    Solution sol;
    cout << (sol.hasAllCodes("00110110", 2) ? "true" : "false") << endl;
    
    return 0;
}