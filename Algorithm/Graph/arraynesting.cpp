#include <climits>
#include <vector>
using namespace std;

class Solution {
    public:
        int arrayNesting(vector<int>& nums) {
            int maximum = INT_MIN;
            vector<bool> visited(nums.size(), false);
            
            for (int i = 0; i < nums.size(); i++) {
                int count = 0;
                
                while (!visited[i]) {
                    visited[i] = true;
                    i = nums[i];
                    count++;
                }

                maximum = std::max(maximum, count);
            }

            return maximum;
        }
};