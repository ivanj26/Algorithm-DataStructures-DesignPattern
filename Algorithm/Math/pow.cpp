#include <iostream>

using namespace std;

double pow(double x, int n) {
    if (n == 0) {
        return 1;
    }

    long nn = n; // INT_MIN <= n <= INT_MAX
    if (nn < 0) {
        x = 1 / x;
        nn = -nn;
    }

    if (nn & 1) { // n is odd
        return x * myPow(x, nn - 1);
    }

    // n is even
    // 2^4 = 4^2
    // make it more faster using this formula

    return myPow(x * x, nn / 2);
}

bool isPowerOfTwo(int n) {
    int count = 0;
    while (n > 0) {
        int lsb = n & 1;
        if (lsb == 1) {
            count++;
        }

        n >>= 1;
    }

    return count == 1;
}

int main(int argc, char const *argv[])
{
    int arr[2];

    if (argc < 3) {
        cout << "insufficient arguments" << endl;
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }

    cout << pow(arr[0], arr[1]) << endl;
    return 0;
}
