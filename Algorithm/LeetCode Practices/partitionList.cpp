#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() {
        val = 0;
        next = nullptr;
    }
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    void addToList(ListNode **head, ListNode *nodeToAdd) {
        if (!nodeToAdd) {
            return;
        }

        nodeToAdd->next = nullptr;

        if (*head == nullptr) {
            *head = nodeToAdd;
        } else {
            ListNode *curr = *head;
            while (curr->next) {
                curr = curr->next;
            }

            curr->next = nodeToAdd;
        }
    }

public:
    ListNodepartition(ListNode *head, int x) {
        ListNode *newList = nullptr;
        ListNode *curr = head;

        queue<ListNode*> q;

        while (curr) {
            ListNode *next = curr->next;

            if (curr->val < x) {
                addToList(&newList, curr);
            } else {
                q.push(curr);
            }
            curr = next;
        }

        while (!q.empty()) {
            ListNode *front = q.front();
            q.pop();

            addToList(&newList, front);
        }

        return newList;
    }
};