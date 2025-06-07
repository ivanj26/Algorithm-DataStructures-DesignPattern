#include <set>
#include <vector>

using namespace std;

class Solution {
    public:
        int getMax(set<int> &s) {
            int maxValue = INT_MIN;

            for (auto el : s) {
                if (el > maxValue) {
                    maxValue = el;
                }
            }

            return maxValue;
        }

        int thirdMax(vector<int>& nums) {
            set<int> s;

            for (int num : nums) {
                s.insert(num);
            }

            if (s.size() >= 3) {
                // Remove the most 2 top/max value from the set
                // Get the 3rd max value
                int maxValue;
                for (int i = 0; i < 2; i++) {
                    maxValue = getMax(s);
                    s.erase(maxValue);
                }

                return getMax(s);
            } else {
                return getMax(s);
            }
        }
};