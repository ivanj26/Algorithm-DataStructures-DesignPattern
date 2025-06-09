#include <algorithm>
using namespace std;

class Solution {
    public:
        int commonFactors(int a, int b) {
            int limit = std::min(a, b);
            int count = 0;

            for (int i = limit; i >= 1; i--) {
                if (a % i == 0 && b % i == 0) {
                    // it means they shared the common factor
                    count++;
                }
            }

            return count;
        }
};