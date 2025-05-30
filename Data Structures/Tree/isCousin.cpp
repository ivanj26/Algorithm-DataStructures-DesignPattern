#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct TNode {
    int lvl;
    TreeNode* node;
    TreeNode* parent;
    TNode(int _lvl, TreeNode* _node, TreeNode* _parent = nullptr): lvl(_lvl), node(_node), parent(_parent) {

    }
};

class Solution {
    public:
        // Two nodes of a binary tree are cousins
        // - if they have the same depth
        // - if they have different parents.
        bool isCousin(TreeNode* root, int x, int y) const {
            queue<TNode*> q;
            q.push(new TNode(0, root));

            // v vector to store the target nodes (x and y)
            vector<TNode*> v;

            while (!q.empty()) {
                TNode* t = q.front();
                q.pop();

                if (t) {
                    TreeNode* node = t->node;
                    if (node->val == x || node->val == y) {
                        // we have found the target whether it is x or y
                        // add the node into vector
                        v.push_back(t);
                    }

                    TreeNode* left = node->left;
                    TreeNode* right = node->right;

                    if (left) {
                        q.push(new TNode(t->lvl + 1, left, node));
                    }

                    if (right) {
                        q.push(new TNode(t->lvl + 1, right, node));
                    }
                }
            }

            // Check: if the vector size is equal to 2
            // If not, return false since we cannot find the pair of x and y
            if (v.size() != 2) {
                return false;
            }

            // The size of vector is confirmed: 2 elements
            TNode* t1 = v[0];
            TNode* t2 = v[1];

            return t1->parent != t2->parent && t1->lvl == t2->lvl;
        }
};