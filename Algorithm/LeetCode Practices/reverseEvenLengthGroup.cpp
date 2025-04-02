// Leetcode problem: https://leetcode.com/problems/reverse-nodes-in-even-length-groups/description/
// You are given the head of a linked list.

// The nodes in the linked list are sequentially assigned to non-empty groups whose lengths form the sequence of the natural numbers (1, 2, 3, 4, ...). The length of a group is the number of nodes assigned to it. In other words,

// The 1st node is assigned to the first group.
// The 2nd and the 3rd nodes are assigned to the second group.
// The 4th, 5th, and 6th nodes are assigned to the third group, and so on.


class Solution {
    private:
        int length(ListNode* node) {
            return node ? 1 + length(node->next) : 0;
        }
    public:
        ListNode* reverseEvenLengthGroups(ListNode* head, int k = 1) {
            if (!head) {
                return head;
            }
    
            int currLen = length(head);
            if (currLen < k) {
                k = currLen;
            }
    
            // If the linkedlist is even length
            // Reverse it!
            if (k % 2 == 0) {
                ListNode* curr = head;
                ListNode* prev = nullptr;
    
                for (int i = 1; i <= k && curr; i++) {
                    ListNode* next = curr->next;
                    curr->next = prev;
                    
                    prev = curr;
                    curr = next;
                }
    
                // Since we have reversed the linkedlist
                // We need to traverse the ll and pointing to the tail of our current group ll
                ListNode* newHead = prev; // Save our head ll of current group
                while (prev->next) {
                    prev = prev->next;
                }
    
                // Reverse the next group by increment the k number
                prev->next = reverseEvenLengthGroups(curr, k+1);
    
                // Return the head of linkedlist
                return newHead;
            } else { // It's odd number, do not reverse the ll
                ListNode* curr = head;
                ListNode* prev = nullptr;
                for (int i = 1; i <= k; i++) {
                    prev = curr;
                    curr = curr->next;
                }
    
                prev->next = reverseEvenLengthGroups(curr, k+1);
                return head;
            }
        }
    };