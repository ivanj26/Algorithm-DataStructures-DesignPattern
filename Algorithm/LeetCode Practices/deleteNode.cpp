// There is a singly-linked list head and we want to delete a node node in it.
// You are given the node to be deleted node. You will not be given access to the first node of head.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        void deleteNode(ListNode* node) {
            if (!node->next) {
                node = nullptr;
                delete node;
                return;
            }

            ListNode* temp = node->next;

            // Replace current node with next node
            node->val = node->next->val;
            node->next = node->next->next;

            delete temp;
        }
};