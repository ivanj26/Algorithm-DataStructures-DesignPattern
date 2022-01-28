struct ListNode {
	ListNode* next;
	int val;

	ListNode(int val) : val(val), next(nullptr) {}
};

class Solution {
	private:
		int len(ListNode* head) {
			return !head ? 0 : (1 + this->len(head->next));
		}

		ListNode* reverseInKGroup(ListNode* head, int k) {
			int length = this->len(head);

			if (length < k) {
				return head;
			}

			ListNode* curr = head;
			ListNode* prev = nullptr;

			for (int i = 0; i < k && curr; i++) {
				ListNode* next = curr->next;
				curr->next = prev;

				prev = curr;
				curr = next;
			}

			head->next = reverseInKGroup(curr, k);
			return prev;
		}

	public:
		ListNode* swapPair(ListNode* head) {
			if (!head || (head && !head->next)) {
				return head;
			}

			return reverseInKGroup(head, 2);
		}
};