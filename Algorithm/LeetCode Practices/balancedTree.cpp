#include <math.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @brief Given a binary tree, determine if it is height-balanced.
 *        For this problem, a height-balanced binary tree is defined as:
 *        a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 * 
 */
class Solution {
    private:
        int height(TreeNode *node) {
            if (!node) {
                return -1;
            }

            int left = 1 + this->height(node->left);
            int right = 1 + this->height(node->right);

            return max(left, right);
        }

    public:
        bool isBalanced(TreeNode* root) {
            if (!root) return true;

            int heightLeft = 1 + this->height(root->left);
            int heightRight = 1 + this->height(root->right);

            if (abs(heightRight - heightLeft) > 1) return false;

            bool lst = this->isBalanced(root->left);
            bool rst = this->isBalanced(root->right);

            return lst && rst;
        }
}