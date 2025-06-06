#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int findPeakElement(vector<int> &arr) {
            int start = 0;
            int end = arr.size() - 1;

            while (start < end) {
                int idxMid = start + ((end - start) / 2);
                int mid = arr[idxMid];

                if (mid < arr[idxMid + 1]) {
                    start = idxMid + 1;
                } else {
                    end = idxMid;
                }
            }

            return start;
        }
};

int main() {
    Solution s;
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);

    cout << s.findPeakElement(arr) << endl;
}