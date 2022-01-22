#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
	private:
		int globalMaxSum;

		int maxSubArrayRecv(vector<int> &nums, int n) {
			if (n == 1) {
				return nums.at(0);
			}

			int currMaxSum = max(nums[n - 1], maxSubArrayRecv(nums, n - 1) + nums[n - 1]);
			globalMaxSum = max(currMaxSum, globalMaxSum);

			return currMaxSum;
		}
	public:
		int maxSubArray(vector<int> &nums) {
			assert(nums.size() > 0);

			globalMaxSum = nums[0];
			maxSubArrayRecv(nums, nums.size());

			return globalMaxSum;
		}
};

int main(int argc, char const *argv[])
{
	Solution sol;
	vector<int> nums = { 5,4,-1,7,8 };
	cout << sol.maxSubArray(nums) << endl;;
	return 0;
}
