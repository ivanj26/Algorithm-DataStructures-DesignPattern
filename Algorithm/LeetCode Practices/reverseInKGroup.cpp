#include <vector>
#include <iostream>

using namespace std;

template <class T>
struct ListNode {
	int val;
	ListNode<T> *next;
	ListNode(int v): val(v) {}
};

int length(ListNode<int> *l) {
	if (!l) {
		return 0;
	}

	return 1 + length(l->next);
}

ListNode<int>* reverseInKGroup(ListNode<int> *l, int k)
{
	if (!l) {
		return nullptr;
	}

	if (length(l) < k) {
		return l;
	}	

	ListNode<int> *prev = nullptr;
	ListNode<int> *curr = l;

	for (int i = 0; i < k && curr; i++) {
		ListNode<int>* next = curr->next;

		curr->next = prev;
		prev = curr;

		curr = next;
	}

	ListNode<int> *head = prev;
	while (prev->next) {
		prev = prev->next;
	}
	
	prev->next = reverseInKGroup(curr, k);

	return head;
}

int main(int argc, char const *argv[])
{
	ListNode<int> *head = new ListNode<int>(1);
	head->next = new ListNode<int>(2);
	head->next->next = new ListNode<int>(3);
	head->next->next->next = new ListNode<int>(4);
	head->next->next->next->next = new ListNode<int>(5);

	ListNode<int> *rev = reverseInKGroup(head, 3);

	while (rev) {
		cout << rev->val << endl;
		rev = rev->next;
	}
	return 0;
}
