#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    private:
        int farthest = 0;
    public:
        int maxDepth(TreeNode* root, int level = 0) {
            if (root) {
                level++;
                farthest = std::max(level, farthest); // Get the maximum level from our current level and farthest

                TreeNode *left = root->left;
                TreeNode *right = root->right;

                return std::max(maxDepth(left, level), maxDepth(right, level));
            }

            return farthest;
        }
};