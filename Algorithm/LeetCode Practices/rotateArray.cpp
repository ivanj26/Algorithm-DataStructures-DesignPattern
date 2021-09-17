#include <vector>

using namespace std;


/**
 * @brief A left rotation operation on an array shifts each of the array's elements unit to the left.
 * 
 * @param arr an array of integers.
 * @param d k places to rotate.
 * @return vector<int> rotated array.
 */
vector<int> rotLeft(vector<int> arr, int d)
{
	int n = arr.size();

	vector<int> suffArr;
	for (int i = d; i < n; i++)
	{
		suffArr.push_back(arr[i]);
	}

	for (int i = 0; i < d; i++)
	{
		suffArr.push_back(arr[i]);
	}

	return suffArr;
}
