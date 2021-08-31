#include <iostream>
using namespace std;

/**
 * Binary search -> only works for sorted array
					mencari elemen dengan membandingkan elemen dengan elemen tengah pada array
 *                  1. Jika x > elemen_tengah, cari elemen di bagian kanan array
 *                  2. Jika x < elemen tengah, cari elemen di bagian kiri array
 *                  3. Jika x == elemen tengah, return index
 * Complexity: O(log n)
 **/
int binarySearch(int *arr, int start, int end, int x)
{
	if (end >= start)
	{
		int idxMid = start + ((end - start) / 2);
		int mid = arr[idxMid];

		if (mid == x)
			return idxMid;
		if (x > mid)
			return binarySearch(arr, idxMid + 1, end, x);
		if (x < mid)
			return binarySearch(arr, start, idxMid - 1, x);
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	const int size = 100;
	int *arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = i * 10;
	}

	cout << sizeof(arr) << endl;
	cout << (binarySearch(arr, 0, size - 1, 100) >= 0 ? "Found" : "Not Found");

	delete[] arr;
	return 0;
}
