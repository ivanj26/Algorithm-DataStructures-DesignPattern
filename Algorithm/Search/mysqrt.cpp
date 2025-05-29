#include <iostream>

using namespace std;

class Solution {
    public:
        int mySqrt(int x) {
            // Handle corner case when x is zero
            if (x == 0) {
                return 0; // sqrt(0) = 0
            }

            int first = 1;
            int last = x;

            while (first <= last) {
                long long mid = first + ((last - first) / 2);

                if (mid*mid == x) {
                    return mid;
                } else if (mid * mid < x) {
                    first = mid + 1; // Increase the lower index to get convergen
                } else {
                    last = mid - 1; // Decrease the higher index to get convergen
                }
            }

            return last;
        }
};

int main() {
    Solution s;
    cout << "Sqrt(8) = " << s.mySqrt(8) << endl;
    return 0;
}