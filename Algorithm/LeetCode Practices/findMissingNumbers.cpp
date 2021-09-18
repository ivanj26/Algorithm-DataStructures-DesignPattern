#include <unordered_map>
#include <vector>

using namespace std;

struct ascending
{
	bool operator()(int i, int j)
	{
		return i < j;
	}
};

/**
 * @brief Given two arrays of integers, find which elements in the second array are missing from the first array.
 * 		  Return the missing numbers sorted ascending.
 * 
 * @example arr 	= [203 204 205 206 207 208 203 204 205 206]
 * 			brr 	= [203 204 204 205 206 207 205 208 203 206 205 206 204]
 * 			result 	= [204 205 206]
 * @param arr first array
 * @param brr second array
 * @return vector<int> result
 */
vector<int> missingNumbers(vector<int> arr, vector<int> brr)
{
	vector<int> missingNums;
	unordered_map<int, int> map;

	for (auto val : brr)
	{
		const bool found = map.find(val) != map.end();
		if (found)
		{
			int counter = map[val];
			map[val] = (++counter);
		}
		else
		{
			map[val] = 1;
		}
	}

	for (auto val : arr)
	{
		const bool found = map.find(val) != map.end();
		if (found)
		{
			int counter = map[val];
			map[val] = --counter;
		}
	}

	for (auto keyVal : map)
	{
		int val = keyVal.second;
		int key = keyVal.first;

		if (val > 0)
		{
			missingNums.push_back(key);
		}
	}

	// - sort the array
	ascending asc;
	std::sort(missingNums.begin(), missingNums.end(), asc);

	return missingNums;
}