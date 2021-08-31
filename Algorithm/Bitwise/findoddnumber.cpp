#include <iostream>
using namespace std;

int findOddNumber(int *arr, int size)
{
	int res = 0;
	for (int i = 0; i < size; i++)
	{
		res ^= arr[i];
	}

	return res;
}

int main(int argc, const char **argv)
{
	int arr[] = {2, 2, 1};
	cout << findOddNumber(arr, 3);

	return 0;
}