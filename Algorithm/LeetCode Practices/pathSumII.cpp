#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class Solution {
    private:
        vector< vector<int> > res;

        void helper(TreeNode * root, int sum, int target, vector<int> v) {
            if (!root) return;

            if (!root->left && !root->right && (root->val + sum == target)) {
                v.push_back(root->val);
                res.push_back(v);
            }

            sum += root->val;

            if (root->left) {
                v.push_back(root->val);
                helper(root->left, sum, target, v);
            }

            if (root->right) {
                if (root->left == nullptr) {
                    v.push_back(root->val);
                }

                helper(root->right, sum, target, v);
            }
        }
    public:
        vector< vector<int >> pathSum(TreeNode* root, int targetSum) {
            vector<int> v;
            helper(root, 0, targetSum, v);

            return res;
        }
};
