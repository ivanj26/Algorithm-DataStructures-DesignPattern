// Given a string containing digits from 2-9 inclusive
// return all possible letter combinations that the number could represent. Return the answer in any order

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//  1    2    3
//      abc  def
//  4    5    6
// ghi  jkl  mno
//  7    8    9
// pqrs  tuv  wxyz

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
    private:
        void backtrack(vector<string> v, vector<string> &out, int maxLen, string tmp = "", int i = 0) {
            if (maxLen == 0) {
                return;
            }

            if (maxLen == tmp.length()) {
                out.push_back(tmp);
                return;
            }

            string s = v[i];
            for (int k = 0; k < s.length(); k++) {
                tmp += s[k];
                backtrack(v, out, maxLen, tmp, i+1);
                tmp.pop_back();
            }
        }
    public:
        vector<string> letterCombinations(string digits) {
            unordered_map<int, string> mp;
        
            mp[2] = "abc";
            mp[3] = "def";
            mp[4] = "ghi";
            mp[5] = "jkl";
            mp[6] = "mno";
            mp[7] = "pqrs";
            mp[8] = "tuv";
            mp[9] = "wxyz";

            vector<string> v;
            for (char c : digits) {
                v.push_back(mp[c - '0']);
            }

            vector<string> out;
            backtrack(v, out, digits.length());

            return out;
        }
};