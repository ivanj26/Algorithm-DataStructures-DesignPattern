#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief The absolute difference is the positive difference between two values a and b, is written |a-b| or |b-a|
 * 
 * @param arr array of integers
 * @return int result
 */
int minimumAbsoluteDifference(vector<int> arr)
{
	struct ascending
	{
		bool operator()(int i, int j)
		{
			return i < j;
		}
	};

	ascending asc;
	std::sort(arr.begin(), arr.end(), asc);

	int minDiff = INT_MAX;
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int absDiff = abs(arr[i + 1] - arr[i]);
		if (absDiff < minDiff)
		{
			minDiff = absDiff;
		}
		if (minDiff == 0)
			return 0;
	}

	return minDiff;
}