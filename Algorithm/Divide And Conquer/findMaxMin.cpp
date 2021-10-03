#include <iostream>
#include <assert.h>
using namespace std;

int findMax(int arr[], int n, int index = 0) {
    assert(n > 0);

    if (n == 1) {
        return arr[index];
    }

    if (index >= n - 2) {
        if (arr[index] > arr[index + 1]) {
            return arr[index];
        }
        return arr[index + 1];
    }

    int max = findMax(arr, n, index + 1);
    if (arr[index] > max) {
        return arr[index];
    }

    return max;
};

int findMin(int arr[], int n, int index = 0) {
    assert(n > 0);

    if (n == 1) {
        return arr[index];
    }

    if (index <= n - 2) {
        if (arr[index] < arr[index + 1]) {
            return arr[index];
        }

        return arr[index + 1];
    }

    int min = findMin(arr, n, index + 1);
    if (arr[index] < min) {
        return arr[index];
    }

    return min;
}


int main(int argc, char const *argv[])
{
    int arr[] = {10, 34, 54, 32, 58, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findMax(arr, n) << endl;
    cout << findMin(arr, n) << endl;
    return 0;
}
