// Definition for singly-linked list:
template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(nullptr) {}
  T value;
  ListNode *next;
};

ListNode<int>* reverse(ListNode<int>* l) {
	ListNode<int>* prev = nullptr;
	while (l) {
		ListNode<int>* next = l->next;
		l->next = prev;
		prev = l;
		l = next;
	}
	return prev;
}

void push(ListNode<int> **root, ListNode<int> *node) {
	if ((*root) == nullptr) {
		(*root) = node;
	} else {
		ListNode<int> *last = *root;
		node->next = last;
		
		*root = node;
	}
}

ListNode<int>* solution(ListNode<int>* a, ListNode<int>* b) {
	a = reverse(a);
	b = reverse(b);
	ListNode<int>* result = nullptr, *itr;
	int sum = 0;
	int carry = 0;
	
	while (a || b || carry) {
		if (a) {
			sum += a->value;
			a = a->next;
		}
		if (b) {
			sum += b->value;
			b = b->next;
		}

		sum = sum + carry;
		
		itr = new ListNode<int>(sum % 10000);
		carry = sum >= 10000 ? sum % 9999 : 0;
		
		push(&result, itr);
		
		sum = 0;
	}
	
	if (carry != 0) {
		itr = new ListNode<int>(carry % 10000);
		push(&result, itr);
	}
	
	return result;
}
