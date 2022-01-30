struct ListNode {
	int val;
	ListNode* next;
	ListNode(int val) : val(val), next(nullptr) {}
};

class Solution {
	private:
		int len(ListNode* curr) {
			return curr ? 1 + len(curr->next) : 0;
		}

		ListNode* swap(ListNode* head) {
			if (len(head) < 2) {
				return head;
			}

			ListNode* curr = head;
			ListNode* prev = nullptr;

			for (int i = 0; i < 2 && curr; i++) {
				ListNode* next = curr->next;
				curr->next = prev;

				prev = curr;
				curr = next;
			}

			head->next = swap(curr);

			return prev;
		}
	public:
		ListNode* swapPairs(ListNode* head) {
			if (!head || (head && !head->next)) {
				return head;
			}

			return swap(head);
		}
};