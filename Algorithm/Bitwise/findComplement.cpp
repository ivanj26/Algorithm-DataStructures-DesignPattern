// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer num, return its complement.
#include <vector>
#include <iostream>
#include <cstdint>

using namespace std;

int findComplement(uint32_t n) {
    vector<int> bits(32, 0);

    int i = 0;
    while (n > 0) {
        int lsb = n & 1;
        bits[i++] = lsb ^ 1;

        n >>= 1;
    }

    int ans = 0;
    for (int j = i - 1; j >= 0; j--) {
        ans += (bits[j] << j);
    }

    return ans;
}

int main() {
    cout << "Complement of 5 (101) = " << findComplement(5) << endl; // result = 2
    cout << "Complement of 6 (110) = " << findComplement(6) << endl; // result = 1
    cout << "Complement of 7 (111) = " << findComplement(7) << endl; // result = 0
    
    return 0;
}
 