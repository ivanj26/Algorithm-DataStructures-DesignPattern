#include <vector>

using namespace std;

class Solution {
    public:
        char nextGreatestLetter(vector<char>& letters, char target) {
            int start = 0;
            int end = letters.size() - 1;
            char first = letters[0];

            while (start <= end) {
                int idxMid = start + ((end - start) / 2);
                int mid = letters[idxMid];

                if (int(mid) > int(target)) { // Our element at index mid is greater lexicographically than our target
                    first = letters[idxMid];
                    end = idxMid - 1; // Search the potential smaller letter on the left side
                } else {
                    start = idxMid + 1; // Otherwise, We should find the potential higher letter on the right part
                }
            }

            return first;
        }
};