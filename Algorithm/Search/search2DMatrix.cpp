#include <vector>

using namespace std;

// 1 3 5 7
// 10 11 16 20
// 23 30 34 60

// target = 50

// My basic idea:
// 1. Do binary search for matrix's row
//    1.1 Check the last element in the row and compare it with target's value
//       
//        If the last element at row-i >= target, it means later
//          we will focus on do binary search on selected row. 
//          Save the row Index to variable `selectedRow`

//    1.2. If the binary search could not find the row index. Let say, the target is 70.
//         Just return rowIndex = -1, and it means we do not have to do binary serach on the selected row since rowindex is -1

// 2. After we get the selected row's index from 1.1 step.
//    Do binary search on selected array in the `selectedRow`

class Solution {
    private:
        int getUpperRowIndex(vector<vector<int>> &mat, int n, int m, int target) {
            int start = 0;
            int end = n - 1;
            int ans = -1;

            while (start <= end) {
                int idxMid = start + ((end - start) / 2);
                int mid = mat[idxMid][m-1]; // get the middle element of our current row

                if (mid >= target) {
                    ans = idxMid;
                    end = idxMid - 1;
                } else {
                    start = idxMid + 1;
                }
            }

            return ans;
        }

    public:
        bool searchMatrix(vector<vector<int>> &matrix, int target) {
            // Let's assume the matrix size minimum is 1x1
            int n = matrix.size();
            int m = matrix[0].size();

            int rowIndex = getUpperRowIndex(matrix, n, m, target);
            if (rowIndex == -1) {
                return false;
            }

            int start = 0;
            int end = m - 1;
            while (start <= end) {
                int idxMid = start + ((end - start) / 2);
                int mid = matrix[rowIndex][idxMid];

                if (mid == target) {
                    return true; // we found the target
                } else if (target < mid) {
                    // target is smaller than our middle element
                    // it means, we need to search on the remaining left part 
                    end = idxMid - 1;
                } else {
                    start = idxMid + 1;
                }
            }

            return false;
        }
};