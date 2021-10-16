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

vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> v;
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];
        int diff2 = target + nums[i];

        unordered_map<int, int>::iterator it = map.find(diff);
        if (it != map.end()) {
            v.push_back(it->second);
            v.push_back(i);
            break;
        }

        unordered_map<int, int>::iterator it2 = map.find(diff2);
        if (it2 != map.end()) {
            v.push_back(it2->second);
            v.push_back(i);
            break;
        }

        map.insert(make_pair(nums[i], i));
    }

    return v;
}