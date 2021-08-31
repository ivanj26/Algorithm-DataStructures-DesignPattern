#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * BubbleSort -> cara sorting/pengurutan dengan melihat tetangga dari elemen yang sedang diiterasi.
 *               Kalau tetangga sebelah kanannya lebih kecil daripada elemen sekarang, maka diswap
 *               Complexity: O(n ^ 2)
 **/
void bubbleSort(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
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

	bubbleSort(arr, size);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}

	return 0;
}