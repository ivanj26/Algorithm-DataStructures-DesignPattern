#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
	unordered_map<int, int> map;

	for (int i = 0; i < nums.size(); i++)
	{
		map.insert({nums[i], i});
	}

	vector<int> res;
	for (int i = 0; i < nums.size(); i++)
	{
		int diff = target - nums[i];
		unordered_map<int, int>::iterator it = map.find(diff);

		if (it != map.end())
		{
			int idx = it->second;
			if (idx != i)
			{
				res.push_back(i);
				res.push_back(idx);

				return res;
			}
		}
	}

	return res;
}