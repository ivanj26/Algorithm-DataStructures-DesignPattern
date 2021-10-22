#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v) {
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    private:
        TreeNode* helper(int end, vector<int> &nums, int start = 0) {
            if (start > end) {
                return nullptr;
            }

            int mid = (start + end) / 2;

            TreeNode* temp = new TreeNode(nums[mid]);
            temp->left = this->helper(mid - 1, nums, start);
            temp->right = this->helper(end, nums, mid + 1);

            return temp;
        }

    public:
        TreeNode* sortedArrToBST(vector<int> &nums) {
            int end = nums.size() - 1;

            return this->helper(end, nums);
        }
};

void printPreOrder(TreeNode* root) {
    if (root) {
        cout << root->val;

        cout << " (";

        printPreOrder(root->left);

        cout << ")";

        cout << " (";

        printPreOrder(root->right);

        cout << ")";
    }
}

int main(int argc, char const *argv[])
{
    vector<int> nums;

    for (int i = -10; i <= 10; i+=2) {
        nums.push_back(i);
    }

    Solution s;
    TreeNode* root = s.sortedArrToBST(nums);

    // print the tree
    printPreOrder(root);

    return 0;
}
