#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right) {
        //
    }

    TreeNode(int _val): val(_val) {
        //
    }
};

bool asc(const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
    return p1.first < p2.first;
}

class Solution {
    private:
        void getAllNumbers(TreeNode *root, std::vector<std::pair<int, int>> &v) {
            if (root) {
                int val = root->val;
                v.push_back(std::make_pair(val, val));

                if (root->left) {
                    this->getAllNumbers(root->left, v);
                }

                if (root->right) {
                    this->getAllNumbers(root->right, v);
                }
            }
        }

        TreeNode* constructNewTree(TreeNode *root, std::unordered_map<int, int> &mp) {
            if (root) {
                // Lookup to the hashmap table
                int sum = mp[root->val];

                TreeNode *newTree = new TreeNode(sum);
                newTree->left = constructNewTree(root->left, mp);
                newTree->right = constructNewTree(root->right, mp);

                return newTree;
            }
        }

    public:
        TreeNode* bstToGst(TreeNode* root) {
            std::vector<std::pair<int, int>> v;
            this->getAllNumbers(root, v);

            std::sort(v.begin(), v.end(), asc);

            int n = v.size();
            for (int i = n - 1; i >= 0; i--) {
                if (i == n - 1) {
                    //skipped
                } else {
                    v[i].second += v[i+1].second;
                }
            }

            std::unordered_map<int, int> mp;
            for (auto p : v) {
                mp[p.first] = p.second;
            }

            return constructNewTree(root, mp);
        }
};