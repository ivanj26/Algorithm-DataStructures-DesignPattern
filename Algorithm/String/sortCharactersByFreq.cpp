#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct descending {
    bool operator()(pair<int, char> x, pair<int, char> y) {
        return x.first > y.first;
    }
};

class Solution {
    public:
        string sortFrequency(string s) {
            unordered_map<char, int> map;

            for (char c : s) {
                map[c]++;
            }

            vector<pair<int, char>> v;
            for (auto it : map) {
                v.push_back(make_pair(it.second, it.first));
            }

            descending desc;
            std::sort(v.begin(), v.end(), desc);

            string res;
            for (int i = 0; i < v.size(); i++) {
                int f = v[i].first;
                char c = v[i].second;

                for (int j = 0; j < f; j++) {
                    res += c;
                }
            }

            return res;
        }
};