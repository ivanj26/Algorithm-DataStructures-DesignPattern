#include <map>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Use sorted map to sorting the node->value and grouping nodes with the same value
        // Map<int, vector<ListNode*>>
        map<int, vector<ListNode*>> mp;

        ListNode* curr = head;
        while (curr) {
            if (mp.find(curr->val) != mp.end()) {
                mp[curr->val].push_back(curr);
            } else {
                mp[curr->val] = vector<ListNode*>(); // create a empty vector/array if the key is not exists
                mp[curr->val].push_back(curr);
            }
            curr = curr->next;
        }

        ListNode* newHead = nullptr;
        ListNode* newCurr;
        
        // Re-construct the new linkedlist based on sorted map
        // Remember in c++: keys are sorted 
        for (auto kv : mp) {
            vector<ListNode*> v = kv.second;

            for (ListNode* node : v) {
                node->next = nullptr; // make sure the next pointer is not pointing to other node

                if (!newHead) {
                    newHead = node;
                    newCurr = node; // our current pointer pointing to our new head ll
                } else { // otherwise, newHead is already exist. 
                    newCurr->next = node;
                    newCurr = newCurr->next; 
                }
            }
        }

        return newHead;
    }
};