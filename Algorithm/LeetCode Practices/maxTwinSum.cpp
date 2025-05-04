// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node,
// if 0 <= i <= (n / 2) - 1.

// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.

// Given the head of a linked list with even length, return the maximum twin sum of the linked list.

#include <climits>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    private:
        int maximum = INT_MIN;
    public:
        int pairSum(ListNode* head) {
            ListNode* left = head;
            ListNode* right = head;
            getMaxPair(&left, right);

            return maximum;
        }

        void getMaxPair(ListNode **left, ListNode *right) {
            if (right->next) {
                getMaxPair(left, right->next);
            }

            // We achieve the tail of linkedlist
            // In this state, :
            // - we have left pointer which pointing the head of ll
            // - we have right pointer which pointign the tail of ll

            int currSum = (*left)->val + right->val;
            maximum = std::max(maximum, currSum);

            // Move the left pointer to next pointer
            (*left) = (*left)->next;
        }
};
