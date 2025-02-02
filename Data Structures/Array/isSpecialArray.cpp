#include <vector>
using namespace std;

// An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
// You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

class Solution {
    public:
        bool isArraySpecial(vector<int>& nums) {
            for (int i = 0; i < nums.size() - 1; i++) {
                int curr = nums[i];
                int next = nums[i+1];

                if (curr % 2 == next % 2) {
                    return false;
                }
            }

            return true;
        }
};