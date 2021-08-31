/**
 * File   : singlylinkedlist2.cpp
 * Author : Ivan Jonathan
 **/

#include "./Node/singlynode.cpp"
#include <cassert>
#include <vector>
#include <set>

using namespace std;

/**
 * SinglyLinkedList2 with tail pointer
 **/
template <class T>
class SinglyLinkedList2
{
	private:
		SinglyNode<T> *head;
		SinglyNode<T> *tail;

	public:
		SinglyLinkedList2(SinglyNode<T> *_head) : head(_head), tail(_head) {}
		SinglyLinkedList2()
		{
			head = nullptr;
			tail = nullptr;
		}
		~SinglyLinkedList2()
		{
			SinglyNode<T> *temp = head;

			while (temp != nullptr)
			{
				SinglyNode<T> *next = temp->getNext();
				delete temp;

				temp = next;
			}
		}

		/* linkedlist operation */
		void push_back(SinglyNode<T> *node)
		{
			if (head != nullptr)
			{
				SinglyNode<T> *last = tail;
				last->setNext(node);

				tail = node;
			}
			else
			{
				head = node;
				tail = node;
			}
		}

		void push_back(T t)
		{
			if (head != nullptr)
			{
				SinglyNode<T> *last = tail;
				SinglyNode<T> *node = new SinglyNode<T>(t);
				last->setNext(node);

				tail = node;
			}
			else
			{
				SinglyNode<T> *node = new SinglyNode<T>(t);
				head = node;
				tail = node;
			}
		}

		T front()
		{
			if (head == nullptr)
			{
				throw "An empty list";
			}
			return head->getData();
		}

		void pop()
		{
			if (head == nullptr)
				return;

			SinglyNode<T> *temp = head;
			SinglyNode<T> *next = temp->getNext();
			delete temp;

			head = next;
		}

		friend ostream &operator<<(ostream &os, SinglyLinkedList2<T> &l)
		{
			SinglyNode<T> *temp = l.getHead();

			while (temp != nullptr)
			{
				os << temp->getData() << endl;
				temp = temp->getNext();
			}

			return os;
		}

		SinglyNode<T> *getHead()
		{
			return head;
		}
};

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
	public:
		ListNode *removeElements(ListNode *head, int val)
		{
			ListNode *prev = nullptr;
			ListNode *next = nullptr;
			ListNode *curr = head;
			bool isHeadDeleted = false;

			while (curr)
			{
				next = curr->next;

				if (curr->val == val)
				{
					if (prev)
					{
						prev->next = next;
					}
					else
					{
						isHeadDeleted = true;
					}

					ListNode *temp = curr;
					delete temp;
				}
				else
				{
					prev = curr;
				}

				curr = next;
			}

			return isHeadDeleted ? prev : head;
		}
};

int main(int argc, char const *argv[])
{
	// SinglyLinkedList2<int> list;

	// try {
	// 	list.push_back(2);
	// 	list.push_back(5);
	// 	list.pop();

	// 	cout << list;
	// } catch (const char* msg) {
	// 	cout << msg;
	// }

	Solution sol;
	ListNode *node1 = new ListNode(7);
	ListNode *node2 = new ListNode(7);
	ListNode *node3 = new ListNode(7);
	ListNode *node4 = new ListNode(7);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = nullptr;

	ListNode *temp = sol.removeElements(node1, 7);
	while (temp)
	{
		cout << temp->val << endl;
		temp = temp->next;
	}

	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete temp;

	return 0;
}
