#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int *arr, int low, int high)
{
	int pivot = (high + low) / 2;

	int i = low;
	int j = high;

	while (i <= j)
	{
		while (arr[i] < pivot)
		{
			i++;
		}

		while (arr[j] < pivot)
		{
			j--;
		}

		if (i <= j)
		{
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}

	return i;
}

void quickSort(int *arr, int low = 0, int high)
{
	if (low <= high)
	{
		int piv = partition(arr, low, high);

		if (low < piv - 1)
		{
			quickSort(arr, low, piv - 1);
		}

		if (high > piv)
		{
			quickSort(arr, piv, high);
		}
	}
}

int main(int argc, const char **argv)
{

	return 0;
}