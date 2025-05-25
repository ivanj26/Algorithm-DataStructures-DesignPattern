#include <iostream>
#include <climits>

using namespace std;

class Solution {
    public:
        double calculatePi(int terms = INT_MAX / 2) {
            // Leibniz formula:

            // pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)

            // Starting with i = 0
            // pi = 4 * ((1/(2 * i) + 1) - (1/(2 * i+1) + 1) + ...)

            double result = 0;
            for (int i = 0; i < terms; i++) {
                double val = 1.0 / ((2*i) + 1);
                int sign = i & 1 ? 1 : 0;
                if (sign) {
                    result -= val;
                } else {
                    result += val;
                }
            }

            return result * 4;
        }
};

int main() {
    Solution s;
    cout << s.calculatePi() << endl;
    return 0;
}