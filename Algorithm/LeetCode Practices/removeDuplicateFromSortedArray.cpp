#include <unordered_map>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &nums)
{
	unordered_map<int, int> map;

	int j = 0;
	int dup = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		unordered_map<int, int>::iterator it = map.find(nums[i]);
		if (it == map.end())
		{
			map.insert(make_pair(nums[i], j));
			j++;
		}
		else
		{
			dup++;
		}
	}

	for (auto keyVal : map)
	{
		nums[keyVal.second] = keyVal.first;
	}

	nums.resize(nums.size() - dup);

	return map.size();
}