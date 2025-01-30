#include <iostream>

using namespace std;

double pow(double x, int n) {
    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        x = 1 / x;
        n = abs(n);
    }

    if (n & 1) {
        return x * pow(x, n - 1);
    } else {
        return pow(x * x, n / 2);
    }
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
