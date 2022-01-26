#include <iostream>
using namespace std;

int partition(int *arr, int low, int high)
{
	// choose most left array value as pivot
	int pivot = arr[low];

	// loop while if low less than high
	while (low < high) {
		while (low < high && pivot <= arr[high]) {
			high--;
		}

		arr[low] = arr[high];

		while (low < high && pivot >= arr[low]) {
			low++;
		}

		arr[high] = arr[low];
	}

	arr[low] = pivot;

	return low;
}

void quickSort(int *arr, int low = 0, int high = INT_MAX)
{
	if (low < high) {
		int mid = partition(arr, low, high);
		quickSort(arr, low, mid);
		quickSort(arr, mid + 1, high);
	}
}

void printArray(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}

int main(int argc, const char **argv)
{
	int size = 5;
	int *arr = new int[size];

	arr[0] = 6;
	arr[1] = 5;
	arr[2] = -4;
	arr[3] = 3;
	arr[4] = 2;

	// apply the quick sort
	quickSort(arr, 0, size - 1);

	// print the array
	printArray(arr, size);

	delete[] arr;
	return 0;
}