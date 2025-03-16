#include <vector>
using namespace std;

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
//
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

class Solution {
    private:
        void solve(vector<int> &inputs, int target, vector<int> &curr, vector<vector<int>> &ans, int index) {
            if (target == 0) {
                ans.push_back(curr);
                return;
            }

            for (int i = index; i < inputs.size(); i++) {
                auto input = inputs[i];
                if (input <= target) {
                    curr.push_back(input);
                    solve(inputs, target - input, curr, ans, i);
                    curr.pop_back();
                }
            }
        }

    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> curr;
            vector<vector<int>> ans;

            solve(candidates, target, curr, ans, 0);
            return ans;
        }
};