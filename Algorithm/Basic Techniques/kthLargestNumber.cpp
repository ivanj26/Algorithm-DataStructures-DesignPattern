#include <iostream>
#include <vector>
#include <algorithm>

struct descending
{
	bool operator()(int i, int j)
	{
		return i > j;
	}
};

int kthLargestNumber(std::vector<int> nums, int k)
{
	descending desc;
	std::sort(nums.begin(), nums.end(), desc);

	int m = k - 1;
	return nums[m];
}

int main(int argc, char const *argv[])
{
	std::vector<int> nums;
	nums.push_back(10);
	nums.push_back(3);
	nums.push_back(0);
	nums.push_back(5);
	nums.push_back(4);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(6);

	int k = 3;

	std::cout << kthLargestNumber(nums, k) << std::endl;
	return 0;
}
