#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * Selection Sort -> Cari yang paling minimum lalu ditukar
 *                   Complexity: O(n^2)
 **/
void selectionSort(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;
		//search for minimum
		for (int j = i + 1; j < size; j++)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}

		//swap element idx_min with element-i
		swap(&arr[i], &arr[min]);
	}
}

int main(int argc, const char **argv)
{
	int size = 10;
	int *arr = new int[size];
	for (int i = size; i > 0; i--)
	{
		arr[(size - i)] = i;
	}

	selectionSort(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}

	delete[] arr;
	return 0;
}