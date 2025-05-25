#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int maxArea(vector<int> &height) {
            int left = 0;
            int right = height.size() - 1;
            int maxArea = INT_MIN;

            while (left < right) {
                int minHeight = min(height[left], height[right]);
                int distance = right - left;
                int currArea = distance * minHeight;

                maxArea = max(currArea, maxArea);

                if (height[left] > height[right]) {
                    right--;
                } else {
                    left++;
                }
            }

            return maxArea;
        }
};