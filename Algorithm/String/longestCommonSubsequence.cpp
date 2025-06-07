#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int longestCommonSubsequence(string &t1, string &t2) {
            vector<int> list(t1.length(), 0);
            // list = [0,0,0,0,0]

            int longest = 0;
            for (char c : t2) {
                int currLen = 0;

                for (int i = 0; i < list.size(); i++) {
                    if (c == t1[i]) {
                        list[i] = currLen + 1;
                        longest = max(longest, list[i]);
                    } else if (currLen < list[i]) {
                        currLen = list[i];
                    }
                }
            }

            return longest;
        }
};

int main() {
    Solution s;

    string t1 = "abcde", t2 = "dbca";
    cout << s.longestCommonSubsequence(t1, t2) << endl;
    return 0;
}