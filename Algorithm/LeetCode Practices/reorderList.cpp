#include <iostream>
#include <queue>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    private:
        int length(ListNode* head) {
            return head == nullptr ? 0 : 1 + length(head->next);
        }

        void reorder(ListNode** left, ListNode *right, queue<ListNode*> &q) {
            if (right == nullptr) {
                return;
            }

            reorder(left, right->next, q);

            q.push(*left);
            q.push(right);

            (*left) = (*left)->next;
        }
    public:
        void reorderList(ListNode* head) {
            queue<ListNode*> q;

            ListNode* left = head;
            ListNode* right = head;
            reorder(&left, right, q);

            int i = 0;
            int len = this->length(head);

            ListNode *tail = nullptr;
            ListNode *newList = nullptr;
            while (!q.empty() && i++ < len) {
                ListNode* front = q.front();
                front->next = nullptr;

                if (newList) {
                    tail->next = front;
                    tail = tail->next;
                } else {
                    newList = front;
                    tail = newList;
                }

                q.pop();
            }

            return newList;
        }
};

void deleteMemory(ListNode *curr) {
    while (curr) {
        ListNode* next = curr->next;
        delete curr;

        curr = next;
    }
}

/**
 * @brief Print the linkedlist.
 * 
 * @param curr 
 */
void printList(ListNode* curr) {
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    ListNode* head = new ListNode(1);
    for (int i = 2; i < 12; i++) {
        ListNode *curr = new ListNode(i);
        push(head, curr);
    }

    // - print linkedlist (before reorder)
    cout << "Before: ";
    printList(head);

    // - do reorder list
    Solution s;
    s.reorderList(head);

    // - print linkedlist (after reorder)
    cout << "After: ";
    printList(head);

    // - clear memory
    deleteMemory(head);
    return 0;
}
