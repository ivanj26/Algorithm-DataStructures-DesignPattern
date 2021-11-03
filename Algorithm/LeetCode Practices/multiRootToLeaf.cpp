#include <string>
#include <vector>

using namespace std;

class Solution {
    private:
        vector<string> res;

    public:
        void helper(TreeNode *root, string s = "")
        {
            if (root)
            {
                if (s.empty())
                {
                    s += to_string(root->val);
                }
                else
                {
                    s += "->" + to_string(root->val);
                }

                if (!root->left && !root->right)
                {
                    res.push_back(s);

                    return;
                }

                helper(root->left, s);
                helper(root->right, s);
            }
        }

        vector<string> binaryTreePaths(TreeNode *root)
        {
            helper(root);

            return res;
        }
};