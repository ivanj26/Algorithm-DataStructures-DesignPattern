#include <iostream>
using namespace std;

// Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

bool hasAlternatingBits(int n) {
    int prev = -1;

    while (n > 0) {
        int lsb = n & 1;
        if (prev == -1) {
            prev = lsb;
        } else {
            if (prev == lsb) {
                return false;
            }

            prev = lsb;
        }

        n >>= 1;
    }

    return true;
}

int main() {
    cout << hasAlternatingBits(5) << endl; // 5 = 101
    cout << hasAlternatingBits(7) << endl; // 7 = 111
    cout << hasAlternatingBits(11) << endl; // 11 = 1011
    return 0;
}