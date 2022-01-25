struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v): val(v) {}
};

class Solution {
	ListNode* reverseBetween(ListNode* head, int left, int right, int i = 1) {
		if (!head) {
			return nullptr;
		}

		// if i < left, do a recursive
		if (i < left) {
			ListNode *reversed = reverseBetween(head->next, left, right, i+1);
			head->next = reversed;

			return head;
		}

		// if i == left
		ListNode* prev = nullptr;
		ListNode* next = nullptr;
		ListNode* curr = head;

		// start reverse in between
		for (; i <= right; i++) {
			next = curr->next;
			curr->next = prev;

			prev = curr;
			curr = next;
		}

		head->next = curr;

		return prev;
	}
};
