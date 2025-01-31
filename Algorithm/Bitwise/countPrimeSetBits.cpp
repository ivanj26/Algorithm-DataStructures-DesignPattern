#include <math.h>
#include <iostream>

// Example 1:

// Input: left = 6, right = 10
// Output: 4
// Explanation:
// 6  -> 110 (2 set bits, 2 is prime)
// 7  -> 111 (3 set bits, 3 is prime)
// 8  -> 1000 (1 set bit, 1 is not prime)
// 9  -> 1001 (2 set bits, 2 is prime)
// 10 -> 1010 (2 set bits, 2 is prime)
// 4 numbers have a prime number of set bits.

// Example 2:

// Input: left = 10, right = 15
// Output: 5
// Explanation:
// 10 -> 1010 (2 set bits, 2 is prime)
// 11 -> 1011 (3 set bits, 3 is prime)
// 12 -> 1100 (2 set bits, 2 is prime)
// 13 -> 1101 (3 set bits, 3 is prime)
// 14 -> 1110 (3 set bits, 3 is prime)
// 15 -> 1111 (4 set bits, 4 is not prime)
// 5 numbers have a prime number of set bits.

class Solution {
    private:
        bool isPrime(int n) {
            int nbits = 0;
            while (n > 0) {
                nbits += n & 1;
                n >>= 1;
            }

            if (nbits <= 1) {
                return false;
            }

            int end = std::sqrt(nbits);
            for (int i = 2; i <= end; i++) {
                if (nbits % i == 0) {
                    return false;
                }
            }

            return true;
        }

    public:
        int countPrimeSetBits(int left, int right) {
            int cnt = 0;
            while (left <= right) {
                if (isPrime(left++)) {
                    cnt++;
                }
            }

            return cnt;
        }
};

int main() {
    Solution s;
    std::cout << "[6,10] = " << s.countPrimeSetBits(6, 10) << std::endl;

    return 0;
}