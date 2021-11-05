struct Tree {
    int val;
    Tree* left;
    Tree* right;

    Tree(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
}

class Solution {
    private:
        int count;

        void tracing(Tree* root, bool isLeft = false) {
            if (!root) return;

            /**
             * if node `root` is terminal / leaf
             * and is left leaf then count it
             * 
             */
            if (!root->left && !root->right) {
                if (isLeft) {
                    count+=root->val;
                }
            }

            tracing(root->left, true);
            tracing(root->right, false);
        }
    public:
        Solution() {
            this->count = 0;
        }

        int sumOfLeftLeaves(Tree* root) {
            tracing(root);

            return count;
        }
};
