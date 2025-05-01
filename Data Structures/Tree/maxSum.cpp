#include <climits>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val) : val(_val) {
        left = nullptr;
        right = nullptr;
    };
};

class Solution
{
  public:
    static void maxSumUtil(TreeNode* root, int &max, int tmp = 0) {
      if (root) {
        if (!root->left && !root->right) {
          int accum = tmp + root->value;
          if (accum > max) {
            max = accum;
          } 
          
          return;
        }
        
        maxSumUtil(root->left, max, tmp + root->value);
        maxSumUtil(root->right, max, tmp + root->value);
      }
    }
  
    static int maxSum(TreeNode* root)
    {
        int max = INT_MIN;
        maxSumUtil(root, max);
        
        return max == INT_MIN ? 0 : max;
    }
};