class Solution {
public:
    int findMin(vector<int>& nums) {
        int minimum = INT_MAX;
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int idxMid = start + (end - start) / 2;
            int mid = nums[idxMid];

            if (mid >= nums[start]) {
               // the next iteration, we need to check the right half from our current middle element
               minimum = min(minimum, nums[start]); // get the local minimum
               start = idxMid + 1;
            } else if (mid <= nums[end]) {
                // the next iteration, we need to check the left half from our curent middle element
                minimum = min(minimum, mid); // get the local minimum
                end = idxMid - 1;
            }
        }

        return minimum; // Global minimum
    }
};