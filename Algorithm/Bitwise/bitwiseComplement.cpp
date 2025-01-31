// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer n, return its complement.

// Example 1:

// Input: n = 5
// Output: 2
// Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
// Example 2:

// Input: n = 7
// Output: 0
// Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
// Example 3:

// Input: n = 10
// Output: 5
// Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.

#include <cstdint>
#include <iostream>

using namespace std;

int bitwiseComplement(uint32_t n) {
    if (n == 0) {
        return 1;
    }
    
    int ans = 0;
    int i = 0;

    while (n > 0) {
        int lsb = n & 1;
        int complement = lsb ^ 1;
        ans = ans | (complement << i);

        i++;
        n >>= 1;
    }

    return ans;
}

int main() {
    cout << bitwiseComplement(5) << endl;
    cout << bitwiseComplement(7) << endl;
    cout << bitwiseComplement(10) << endl;
    return 0;
}