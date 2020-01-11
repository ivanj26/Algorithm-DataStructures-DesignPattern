#include <iostream>
using namespace std;

/**
 * Binary search -> mencari elemen dengan membandingkan elemen dengan elemen tengah pada array
 *                  1. Jika x > elemen_tengah, cari elemen di bagian kanan array
 *                  2. Jika x < elemen tengah, cari elemen di bagian kiri array
 *                  3. Jika x == elemen tengah, return index
 * Complexity: O(log n)
 **/ 
int binarySearch(int* arr, int start, int end, int x) {
  if (end >= start) {
    int idx_mid = start + (end - start) / 2;
    int mid = arr[idx_mid];

    cout << mid << endl;
    if (mid == x) return idx_mid;
    else if (mid > x) {
      return binarySearch(arr, start, idx_mid - 1, x);
    } else {
      return binarySearch(arr, idx_mid + 1, end, x);
    }
  }

  return -1;
}

int main(int argc, char const *argv[])
{
  const int size = 100;
  int* arr = new int[size];

  for (int i = 0; i < size; i++)
  {
    arr[i] = i * 10;
  }

  cout << (binarySearch(arr, 0, size-1, 70) >= 0? "Found" : "Not Found");

  delete[] arr;
  return 0;
}
