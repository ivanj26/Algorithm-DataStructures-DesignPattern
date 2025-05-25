#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    private:
        string countingSort(string s) {
            int *counter = new int[26];
            fill_n(counter, 26, 0);

            for (char c : s) {
                counter[c - 'a']++;
            }

            stringstream ss;
            for (int i = 0; i < 26; i++) {
                int freq = counter[i];
                for (int j = 1; j <= freq; j++) {
                    ss << (i + 'a');
                }
            }
            delete[] counter;

            return ss.str();
        }
    public:
        vector<vector<string>> groupAnagrams(vector<string> &strs) {
            unordered_map<string, vector<string>> mp;
            for (string s : strs) {
                string sorted = this->countingSort(s);

                if (mp.find(sorted) == mp.end()) {
                    mp[sorted] = {s};
                } else {
                    mp[sorted].push_back(s);
                }
            }

            vector<vector<string>> out;
            for (auto kv : mp) {
                out.push_back(kv.second);
            }
            
            return out;
        }
};