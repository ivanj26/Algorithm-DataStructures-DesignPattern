#include <vector>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * @brief Reverse array without extra memory (using stack or new array as a temporary container).
 * Time complexity: O(n)
 * Space complexity: O(1)
 * 
 * @param arr 
 * @return vector<int> 
 */
vector<int> reverseArray(vector<int> arr)
{
	int size = arr.size();
	int n = size / 2;

	int i = 0;
	while (i < n)
	{
		int j = size - i - 1;
		swap(&arr[i], &arr[j]);

		i++;
	}

	return arr;
}