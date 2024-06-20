struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool isSubPathUtil(ListNode* node, TreeNode* root) {
        if (!node) {
            return true;
        }

        if (!root) {
            return false;
        }

        if (node->val == root->val) {
            ListNode* next = node->next;
            return isSubPathUtil(next, root->left) || isSubPathUtil(next, root->right);
        }

        return false;
    }

    public:
        bool isSubPath(ListNode* head, TreeNode* root) {
            if (!root) {
                return 0;
            }

            if (isSubPathUtil(head, root)) {
                return true;
            }

            return isSubPath(head, root->left) || isSubPath(head, root->right);
        }
};
