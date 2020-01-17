#include <iostream>
#include <math.h>
using namespace std;

/**
 * JumpSearch -> mengecek lebih sedikit element dibandingkan dengan linear search
 *               ketika melakukan pencarian, jump search akan melewati beberapa elemen karena akan elemen dilompati
 *               sebanyak variabel step = sqrt(ukuran array)
 *               1. Jika ketemu, return index;
 *               2. Jika lebih kecil, maka kembali ke elemen sebelumnya, lalu lakukan linear search
 *               3. Kondisi berhenti jika index_curr >= size (ukuran array)
 *               Complexity: O(sqrt(n))
 *               LinearSearch > JumpSearch > BinarySearch
 *               O(n) > O(sqrt(n)) > O(log n)
 **/
int jumpSearch(int* arr, int size, int x) {
    int step = int(sqrt(size));
    int curr = 0;
    int prev = 0;

    while (curr <= size) {
        if (arr[curr] == x) {
            return curr;
        } else if (arr[curr] > x) {
            curr = prev;
            step = 1;
        } else {
            prev = curr;
            curr += step;
            curr = curr >= size ? curr-1 : curr; 
        }
    }

    return -1;
}

int main(int argc, const char** argv) {
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 
                34, 55, 89, 144, 233, 377, 610 };
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << (jumpSearch(arr, n, 377) > -1 ? "Found" : "Not Found") << endl; 
    return 0;
}