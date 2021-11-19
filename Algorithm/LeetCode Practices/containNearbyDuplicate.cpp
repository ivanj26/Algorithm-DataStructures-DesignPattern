#include <unordered_map>
#include <vector>
#include <math>

using namespace std;

class Solution {
	public:
		bool containNearbyDuplicate(vector<int> &nums, int k)
		{
			unordered_map<int, int> map;
			int size = nums.size();

			// map[val] = index;

			for (int i = 0; i < size; i++)
			{
				int val = nums[i];

				if (map.find(val) != map.end()) // check duplicate
				{
					int index = map[val];
					if (abs(i - index) <= k)
					{
						return true;
					}
				}

				map[val] = i;
			}

			return false;
		}
};