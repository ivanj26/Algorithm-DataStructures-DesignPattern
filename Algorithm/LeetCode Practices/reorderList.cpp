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

// - global variable to counting recursive steps.
int counter = 1;

class Solution
{
    private:
        /**
         * @brief Helper to count the linkedlist
         * 
         * @param curr 
         * @return int 
         */
        int count(ListNode *curr)
        {
            int i = 0;

            while (curr)
            {
                curr = curr->next;
                i += 1;
            }

            return i;
        }

        /**
         * @brief reorderList helper.
         * @param left the most left pointer.
         * @param right the most right pointer.
         * @param &q  the reference of queue object.
         * @param count the length of linkedlist
         * 
         * @param bool
         */
        bool reorder(ListNode **left, ListNode *right, queue<ListNode *> &q, int count)
        {
            // - move the pointer until the most right of linkedlist
            if (right == nullptr)
            {
                return true;
            }

            bool flag = reorder(left, right->next, q, count);
            if (flag == false)
            {
                return false;
            }

            // - push left and right pointer into queue.
            // L0 -> Ln -> L1 -> Ln-1 ... continue
            // We must do this step until (length of linkedlist) / 2
            // to prevent un-unique element filled in queue
            int c = count % 2 == 0 ? count / 2 : (count / 2) + 1;
            if (counter == c)
            {
                q.push(*left);
                q.push(right);

                // - if we reached the c variable, we will not move the left pointer anymore and do not increase the counter
                return false;
            }
            else
            {
                q.push(*left);
                q.push(right);

                // - do a 1 step for the left pointer
                (*left) = (*left)->next;
                counter++;

                return true;
            }
        }

    public:
        /**
         * @brief Reorder the list to be on the following form:
         * from : L0 → L1 → … → Ln - 1 → Ln
         * to   : L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
         * 
         * @param head 
         */
        void reorderList(ListNode *head)
        {
            ListNode *newHead = head;
            int count = this->count(head);
            queue<ListNode *> q;

            // call recursive reorder function
            reorder(&newHead, head, q, count);

            ListNode *res = nullptr;

            while (!q.empty())
            {
                ListNode *front = q.front();
                q.pop();

                if (res == nullptr)
                {
                    res = front;
                    res->next = nullptr;
                }
                else
                {
                    ListNode *curr = res;

                    while (curr->next)
                    {
                        curr = curr->next;
                    }

                    curr->next = front;
                    curr->next->next = nullptr;
                }
            }

            head = res;
        }
};

/**
 * @brief Push new ListNode into tail of linkedlist
 * 
 * @param head 
 * @param newNode 
 */
void push(ListNode* head, ListNode* newNode) {
    ListNode* curr = head;
    while (curr->next) {
        curr = curr->next;
    }

    curr->next = newNode;
}

/**
 * @brief Delete all list node in linkedlist.
 * 
 * @param curr 
 */
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
