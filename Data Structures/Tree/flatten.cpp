#include <queue>
#include <iostream>

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

class Solution {
    private:
        void collectTree(TreeNode *root, queue<TreeNode*> &q) {
            if (root) {
                q.push(root);

                if (root->left) {
                    this->collectTree(root->left, q);
                }

                if (root->right) {
                    this->collectTree(root->right, q);
                }
            }
        }

        TreeNode *flattenTree(queue<TreeNode*> &q) {
            TreeNode *root = q.front();
            q.pop();

            TreeNode *node = root;

            while (!q.empty()) {
                node->right = q.front();
                node->left = nullptr;

                node = node->right;

                q.pop();
            }

            return root;
        }
    public:
        void flatten(TreeNode *root) {
            if (!root) {
                return;
            }

            queue<TreeNode *> q;
            q.push(root);

            this->collectTree(root->left, q);
            this->collectTree(root->right, q);

            root = this->flattenTree(q);
        }
};

//Left - Root - Right
void printInOrder(TreeNode *tree)
{
    if (!tree)
        return;

    cout << "(";
    printInOrder(tree->left);
    cout << ")";

    cout << " (";
    cout << tree->val;
    cout << ") ";

    cout << "(";
    printInOrder(tree->right);
    cout << ")";
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);

    Solution sol;
    sol.flatten(root);

    printInOrder(root);
    return 0;
}
