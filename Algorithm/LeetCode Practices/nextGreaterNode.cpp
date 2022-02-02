#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* searchGreater(ListNode* curr, int val) {
		if (curr) {
			return val < curr->val ? curr : searchGreater(curr->next, val);
		}
		
		return nullptr;
	}
	
	vector<int> nextLargerNodes(ListNode* head) {
		ListNode* curr = head;
		vector<int> res;
		
		while (curr) {
			ListNode* next = curr->next;
			ListNode* nextGreater = searchGreater(next, curr->val);
			
			if (nextGreater) {
				res.push_back(nextGreater->val);
			} else {
				res.push_back(0);
			}
			
			curr = curr->next;
		}
		
		return res;
	}
};