#include <vector>
#include <iostream>

using namespace std;

int maxProductSubArray(vector<int> nums){
	int res = *max_element(nums.begin(), nums.end());
	int max = 1;
	int min = 1;

	for (auto n : nums) {
		int tmp = max * n;
		max = std::max({ tmp, min * n, n });
		min = std::min({ tmp, min * n, n });

		res = std::max(max, res);
		// cout << max << endl;
	}

	// cout << endl;

	return res;
}

int main(int argc, char const *argv[])
{
	vector<int> v = { 1, 2, 0, 4, -1, 4, 5 };
	cout << "Result: " << maxProductSubArray(v) << endl;
	return 0;
}
