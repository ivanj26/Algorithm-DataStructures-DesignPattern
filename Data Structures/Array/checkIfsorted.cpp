#include <vector>
using namespace std;

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: true
// Explanation: [1,2,3,4,5] is the original sorted array.
// You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].

// -------------------------------------------------------------------------------------------------------------

// Example 2:

// Input: nums = [2,1,3,4]
// Output: false
// Explanation: There is no sorted array once rotated that can make nums.
// Example 3:

// Input: nums = [1,2,3]
// Output: true
// Explanation: [1,2,3] is the original sorted array.
// You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.

class Solution {
    private:
        int findMinIdx(vector<int> &nums) {
            int min = nums[0];
            int idxMin = 0;
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (min >= nums[i]) {
                    min = nums[i];
                    idxMin = i;
                } else {
                    if (idxMin != 0) {
                        return idxMin;
                    }
                }
            }

            for (int i = 1; i < nums.size(); i++) {
                if (min > nums[i]) {
                    min = nums[i];
                    idxMin = i;
                }
            }

            return idxMin;
        }
    public:
        bool check(vector<int>& nums) {
            int idxMin = findMinIdx(nums);
            int end = nums.size() - 1;
            int prev = -1;
            
            while (end >= 0) {
                if (idxMin >= nums.size()) {
                    idxMin = 0;
                }

                if (prev <= nums[idxMin]) {
                prev = nums[idxMin]; 
                } else {
                    return false;
                }

                idxMin++;
                end--;
            }

            return true;
        }
};