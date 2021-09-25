#include <vector>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int removeElement(vector<int> &nums, int val)
{
	int j = nums.size() - 1;
	int sum = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (val == nums[i])
		{
			sum++;
			nums[i] = -1;

			swap(&nums[i], &nums[j]);
			j--;
			i--;
		}
	}

	int resize = nums.size() - sum;
	nums.resize(resize);

	return resize;
}