#include <vector>
#include <climits>

using namespace std;

class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            int sum = 0;
            int maxSum = INT_MIN;
            int j = 0;
            
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];

                if (i - j + 1 == k) {
                    maxSum = max(maxSum, sum);
                    sum -= nums[j];
                    j++;
                }
            }

            return static_cast<double>(maxSum) / k;
        }
};