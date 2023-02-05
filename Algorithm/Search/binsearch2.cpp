#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int start = 0;
            int end = nums.size() - 1;

            while (start <= end) {
                int idxMid = start + ((end - start) / 2);
                int mid = nums[idxMid];

                if (mid == target) {
                    return idxMid;
                } else if (mid < target) {
                    start = idxMid + 1; // search target in right hand side
                } else {
                    end = idxMid - 1; // search target in left hand side
                }
            }

            return -1;
        }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> v;
    for (size_t i = 0; i < 10; i++)
    {
        v.push_back(i * 2);
    }

    cout << "Index of 6 => " << sol.search(v, 6) << endl;

    return 0;
}
