// Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.
// A subtree of a node `node` is node plus every node that is a descendant of node.

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* left;
    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    public:
        TreeNode* pruneTree(TreeNode* root) {
            if (root) {
                TreeNode* left = pruneTree(root->left);
                TreeNode* right = pruneTree(root->right);

                if (!left && !right && root->val == 0) {
                    return nullptr;
                }
            }

            return root;
        }
};