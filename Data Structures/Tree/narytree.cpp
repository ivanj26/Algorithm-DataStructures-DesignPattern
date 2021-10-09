#include <vector>

using namespace std;

class Tree {
    private:
        int val;
        vector<Tree*> children;
    public:
        int getValue() {
            return val;
        }

        vector<Tree*> getChildren() const {
            return children;
        }
};

class Solution {
    private:
        vector<int> v;

        void preorderUtil(Tree* root) {
            if (!root) {
                return;
            }

            v.push_back(root->val);

            for (Tree* child : root->getChildren()) {
                preorderUtil(child);
            }
        }

        void postorderUtil(Tree* root) {
            if (!root) {
                return;
            }

            for (Tree* child : root->getChildren()) {
                postorderUtil(child);
            }

            v.push_back(root->val);
        }
    public:
        vector<int> preorder(Tree* root) {
            preorderUtil(root);

            return v;
        }

        vector<int> postorder(Tree* root) {
            postorderUtil(root);

            return v;
        }
};