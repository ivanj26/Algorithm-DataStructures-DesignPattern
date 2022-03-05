#include <iostream>
using namespace std;

long sumOfAllSubArrays(int arr[], int n) {
    long result = 0;

    // [1,2,3]
    // sub array: [1], [2], [3], [1,2], [2,3], [1,2,3]
    // 1 : occurs 3times
    // 2 : occurs 4times
    // 3 : occurs 3times

    // (1 * 3) + (2 * 4) + (3 * 3) = 20

    for (size_t i = 0; i < n; i++) {
        result += (arr[i] * (n - i) * (i + 1));
    }

    return result;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3};
    cout << sumOfAllSubArrays(arr, 3) << endl;
    return 0;
}
