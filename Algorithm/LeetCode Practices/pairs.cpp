#include <set>
#include <vector>

using namespace std;

/**
 * @brief Given an array of integers and a target value, determine the number of pairs of array elements that have a difference equal to the target value.
 * 
 * @param k An integer, the target difference
 * @param arr An array of integers
 * @return The number of pairs that satisfy the criterion
 */
int pairs(int k, vector<int> arr)
{
	set<int> s;
	int count = 0;

	for (auto val : arr)
	{
		if (val == 1)
		{
			s.insert(val);
		}
		else
		{ // val > 1
			int diff = val - k;
			int diff2 = val + k;
			if (s.find(diff) != s.end())
			{
				count++;
			}

			if (s.find(diff2) != s.end())
			{
				count++;
			}

			s.insert(val);
		}
	}

	return count;
}