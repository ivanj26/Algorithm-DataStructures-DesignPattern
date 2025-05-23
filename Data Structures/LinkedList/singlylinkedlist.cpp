/**
 * File   : singlylinkedlist.cpp
 * Author : Ivan Jonathan
 **/

#include "./Node/singlynode.cpp"
#include <cassert>
#include <vector>
#include <set>
#include <stack>

using namespace std;

template <class T>
class SinglyLinkedList
{
	private:
		SinglyNode<T> *head;

		/**
			 * @brief Utility for isPalindrome() to get palindrome of linkedlist by using recursive strategy.
			 * 
			 * @param left 
			 * @param right 
			 * @return bool 
			 */
		bool isPalindromeUtil(SinglyNode<T> **left, SinglyNode<T> *right)
		{
			if (right == nullptr)
				return true;

			bool isp = this->isPalindromeUtil(left, right->getNext());
			if (isp == false)
				return false;

			bool isp2 = (*left)->getData() == right->getData();
			(*left) = (*left)->getNext();

			return isp2;
		}

		/**
			 * @brief Utility for removeKFromList().
			 * 
			 * @param head 
			 * @param k 
			 * @return SinglyNode<T>* 
			 */
		SinglyNode<T> *removeKFromList(SinglyNode<T> *head, T k)
		{
			if (head == nullptr)
			{
				return head;
			}

			head->setNext(this->removeKFromList(head->getNext(), k));
			if (head->getData() == k)
			{
				SinglyNode<T> *next = head->getNext();
				SinglyNode<T> *temp = head;
				delete temp;

				return next;
			}
			else
			{
				return head;
			}
		}

		/**
			 * @brief Utility for subtractOne().
			 * 
			 * @param node 
			 * @return int 
			 */
		int subtractOneUtil(SinglyNode<T> *node)
		{
			if (node == nullptr)
			{
				return -1;
			}

			int borrow = subtractOneUtil(node->getNext());
			if (borrow == -1)
			{
				if (node->getData() == 0)
				{
					node->setData(9);
					return -1;
				}
				else
				{
					T subtracted = node->getData() - 1;
					node->setData(subtracted);
					return 0;
				}
			}

			return 0;
		}

		/**
			 * @brief Utility to help move even numbers to the end of list.
			 * 
			 * @param odd 
			 * @param even 
			 * @param i 
			 * @return SinglyNode<T>* 
			 */
		SinglyNode<T> *oddEvenRecv(SinglyNode<T> *odd, SinglyNode<T> **even, int i = 0)
		{
			if (odd == nullptr)
			{
				return odd;
			}

			odd->setNext(this->oddEvenRecv(odd->getNext(), even, ++i));
			if (i % 2 == 0)
			{
				if ((*even) == nullptr)
				{
					(*even) = new SinglyNode<T>(odd->getData());
					(*even)->setNext(nullptr);
				}
				else
				{
					SinglyNode<T> *temp = *even;
					while (temp->getNext())
					{
						temp = temp->getNext();
					}

					temp->setNext(new SinglyNode<T>(odd->getData()));
				}

				return odd->getNext();
			}

			return odd;
		}

		/**
			 * @brief Utility function to help rotate linkedlist.
			 * 
			 * @param curr 
			 * @param end 
			 * @return SinglyNode<T>* 
			 */
		SinglyNode<T> *rotate(SinglyNode<T> *curr, SinglyNode<T> **end)
		{
			if (curr->getNext() == nullptr)
			{
				*end = curr;
				return nullptr;
			}

			curr->setNext(rotate(curr->getNext(), end));
			return curr;
		}

		/**
			 * @brief Reverse the linkedlist using recursive approach.
			 * 
			 * @param SinglyNode<T>* node
			 */
		// SinglyNode<T> *reverseRecv(SinglyNode<T> *node = this->front())
		// {
		// 	if (node == nullptr || node->getNext() == nullptr)
		// 	{
		// 		return node;
		// 	}

		// 	SinglyNode<T> *revHead = this->reverseRecv(node->getNext());
		// 	SinglyNode<T> *tail = node->getNext();
		// 	tail->setNext(node);
		// 	node->setNext(nullptr);

		// 	return revHead;
		// }

	public:
		/**
			 * @brief Construct a new Singly Linked List object.
			 * 
			 */
		SinglyLinkedList()
		{
			head = nullptr;
		}

		/**
			 * @brief Construct a new Singly Linked List object.
			 * 
			 */
		SinglyLinkedList(int v)
		{
			head = new SinglyNode<T>(v);
		}

		/**
			 * @brief Copy construct a Singly Linked List object
			 * 
			 * @param list 
			 */
		SinglyLinkedList(const SinglyLinkedList<T> &list)
		{
			head = list.head;
		}

		/**
			 * @brief Construct a new Singly Linked List object
			 * 
			 * @param _head 
			 */
		SinglyLinkedList(SinglyNode<T> *_head) : head(_head) {}

		/**
			 * @brief Replace left hand pointer with right hand pointer.
			 * 
			 * @param l 
			 * @return SinglyLinkedList& 
			 */
		SinglyLinkedList &operator=(const SinglyLinkedList<T> &l)
		{
			swap(*this, l);

			return *this;
		}

		/**
			 * @brief Destroy the Singly Linked List object
			 * @return void
			 */
		~SinglyLinkedList()
		{
			SinglyNode<T> *curr = head;

			while (curr != nullptr)
			{
				SinglyNode<T> *next = curr->getNext();

				delete curr;
				curr = next;
			}
		}

		/**
			 * @brief Print the linkedlist using operator <<.
			 * 
			 * @param os 
			 * @param l 
			 * @return ostream& 
			 */
		friend ostream &operator<<(ostream &os, SinglyLinkedList &l)
		{
			SinglyNode<T> *temp = l.front();

			while (temp != nullptr)
			{
				os << temp->getData() << endl;
				temp = temp->getNext();
			}

			return os;
		}

		/************************
			/* Linkedlist operation
			/************************

			/**
			 * @brief Get head of SinglyLinkedList.
			 * @return SinglyNode<T>*
			 */
		SinglyNode<T> *front() { return head; }

		/**
			 * @brief Push new element into tail of SinglyLinkedList.
			 * @param t 
			 * @return void
			 */
		void push(T t)
		{
			SinglyNode<T> *temp = head;

			if (temp == nullptr)
			{
				head = new SinglyNode<T>(t);
			}
			else
			{
				while (temp->getNext() != nullptr)
				{
					temp = temp->getNext();
				}

				temp->setNext(new SinglyNode<T>(t));
			}
		}

		/**
			 * @brief Push new element into tail of SinglyLinkedList.
			 * 
			 * @param node 
			 * @return void
			 */
		void push(SinglyNode<T> *node)
		{
			SinglyNode<T> *temp = head;

			if (temp == nullptr)
			{
				head = node;
			}
			else
			{
				while (temp->getNext() != nullptr)
				{
					temp = temp->getNext();
				}

				temp->setNext(node);
			}
		}

		/**
			 * @brief Delete element in SinglyLinkedList at a given index.
			 * 
			 * @param idx
			 * @return void
			 */
		void deleteAt(long idx)
		{
			// - check if index is correct or not
			assert(idx >= 0);

			if (head == nullptr)
				return;

			if (idx > 0)
			{
				long i = 0;
				SinglyNode<T> *prev = nullptr;
				SinglyNode<T> *curr = head;
				SinglyNode<T> *next = curr->getNext();

				while (i < idx && curr)
				{
					prev = curr;
					curr = next;

					if (next == nullptr)
					{
						cout << "Index out of bound!" << endl;
						return;
					}
					else
					{
						next = next->getNext();
					}

					i++;
				}

				if (prev != nullptr)
				{
					prev->setNext(next);
				}

				delete curr;
			}
			else
			{
				head = next;
			}
		}

		/**
			 * @brief Get length of SinglyLinkedList.
			 * 
			 * @return long 
			 */
		long count()
		{
			if (head == nullptr)
			{
				return 0;
			}

			SinglyNode<T> *temp = head;
			long c = 0;
			while (temp)
			{
				temp = temp->getNext();
				c++;
			}

			return c;
		}

		/**
			 * @brief Get first occurence from a given value in SinglyLinkedList.
			 * 
			 * @param value 
			 * @return long 
			 */
		long search(T value)
		{
			SinglyNode<T> *temp = head;

			long idx = 0;
			while (temp != nullptr)
			{
				if (temp->getData() == value)
				{
					return idx;
				}

				temp = temp->getNext();
				idx++;
			}

			return -1;
		}

		/**
			 * @brief Get all occurences from a given value in SingleLinkedList.
			 * 
			 * @param value 
			 * @return vector<int> 
			 */
		vector<int> searchOccurrences(T value)
		{
			vector<int> vec;
			SinglyNode<T> *temp = head;
			long i = 0;

			while (temp != nullptr)
			{
				if (temp->getData() == value)
				{
					vec.push_back(i);
				}

				i++;
				temp = temp->getNext();
			}

			return vec;
		}

		/**
			 * @brief Get element at a given index.
			 * 
			 * @param idx 
			 * @return T 
			 */
		T at(long idx)
		{
			// - check if index is correct or not
			assert(idx >= 0);

			SinglyNode<T> *temp = head;
			long i = 0;

			while (temp != nullptr)
			{
				if (idx == i)
					return temp->getData();
				temp = temp->getNext();
				i++;
			}

			return -1;
		}

		/**
			 * @brief Get nth element from last node.
			 * @return T
			 */
		T getNthFromEnd(int n)
		{
			int start = 1;
			SinglyNode<T> *fast = head;
			SinglyNode<T> *slow = head;

			while (fast->getNext())
			{
				fast = fast->getNext();
				start++;

				if (start > n)
				{
					slow = slow->getNext();
				}
			}

			return slow->getData();
		}

		/**
			 * @brief Remove nth element from last node.
			 */
		SinglyLinkedList<T> removeNthNodeFromEnd(int n)
		{
			int start = 1;
			SinglyNode<T> *prev = nullptr;
			SinglyNode<T> *slow = head;
			SinglyNode<T> *fast = head;

			while (fast->getNext())
			{
				fast = fast->getNext();

				if (start >= n)
				{
					prev = slow;
					slow = slow->getNext();
				}

				start++;
			}

			if (prev)
			{
				prev->setNext(slow->getNext());
			}

			SinglyNode<T> *head2 = head == slow ? slow->getNext() : head;
			return SinglyLinkedList<T>(head2);
		}

		/**
			 * @brief Print "sub" linkedlist from a given index.
			 * 
			 * @param idx 
			 * @return void
			 */
		void printNthToLast(long idx)
		{
			assert(idx >= 0);

			long i = 0;
			SinglyNode<T> *temp = head;

			while (temp != nullptr && i < idx)
			{
				temp = temp->getNext();
				i++;
			}

			while (temp != nullptr)
			{
				cout << temp->getData() << endl;
				temp = temp->getNext();
			}
		}

		/**
			 * @brief Print all elements in linkedlist.
			 * 
			 * @return void
			 */
		void print()
		{
			SinglyNode<T> *temp = head;
			while (temp)
			{
				cout << temp->getData() << endl;

				temp = temp->getNext();
			}
		}

		/**
			 * @brief 
			 * 
			 * @param from 
			 * @param to 
			 * @return SinglyLinkedList<T> 
			 */
		SinglyLinkedList<T> sub(long from, long to)
		{
			// - check if given indices are correct
			assert(from <= to && from >= 0 && to >= 0);

			long i = 0;
			SinglyNode<T> *temp = head;

			while (i < from && temp != nullptr)
			{
				temp = temp->getNext();
				i++;
			}

			SinglyLinkedList<T> list;
			for (long j = from; j <= to; j++)
			{
				if (temp != nullptr)
				{
					list.push(temp->getData());
					temp = temp->getNext();
				}
				else
					return list;
			}

			return list;
		}

		/**
			 * @brief Return true if linkedlist has a cycle.
			 * 
			 * @return bool 
			 */
		bool isCyclic()
		{
			set<SinglyNode<T> *> s;

			SinglyNode<T> *temp = head;
			while (temp != nullptr)
			{
				if (s.find(temp) != s.end())
					return true;
				s.insert(temp);

				temp = temp->getNext();
			}

			return false;
		}

		/**
			 * @brief Check if linkedlist is a palindrome list.
			 * 
			 * @return bool
			 */
		bool isPalindrome()
		{
			if (head == nullptr)
				return true;

			stack<T> s;
			SinglyNode<T> *temp = head;
			while (temp != nullptr)
			{
				s.push(temp->getData());
				temp = temp->getNext();
			}

			temp = head;

			while (!s.empty())
			{
				T top = s.top();
				s.pop();

				if (top != temp->getData())
					return false;
				temp = temp->getNext();
			}

			return true;
		}

		/**
			 * @brief Check if linkedlist is a palindrome list using recursive. (Without stack)
			 * 
			 * @return bool
			 */
		bool isPalindrome2()
		{
			SinglyNode<T> *temp = head;
			return this->isPalindromeUtil(&temp, head);
		}

		/**
			 * @brief Remove duplicated element in SinglyLinkedList with two loops.
			 * 
			 * @return void
			 */
		void removeDuplicates()
		{
			SinglyNode<T> *curr = head;

			while (curr != nullptr)
			{
				SinglyNode<T> *runner = curr->getNext();
				SinglyNode<T> *prevRunner = curr;

				while (runner != nullptr)
				{
					if (runner->getData() == curr->getData())
					{
						prevRunner->setNext(runner->getNext());
						delete runner;

						runner = prevRunner->getNext();
					}
					else
					{
						prevRunner = runner;
						runner = runner->getNext();
					}
				}

				curr = curr->getNext();
			}
		}

		/**
			 * @brief Remove duplicated element in SinglyLinkedList using Set (with extra memory but efficient in time).
			 * 
			 * @return void
			 */
		void removeDuplicatesUsingSet()
		{
			set<T> s;

			SinglyNode<T> *curr = head;
			SinglyNode<T> *prev = nullptr;

			while (curr != nullptr)
			{
				bool isDuplicate = s.find(curr->getData()) != s.end();

				if (isDuplicate)
				{
					SinglyNode<T> *next = curr->getNext();
					prev->setNext(next);
					delete curr;
				}
				else
				{
					s.insert(curr->getData());
					prev = curr;
				}

				curr = prev->getNext();
			}
		}

		/**
			 * @brief Remove duplicates for corner case.
			 * 
			 */
		SinglyLinkedList<T> removeDuplicatesUsingSet2()
		{
			SinglyNode<T> *prev;
			SinglyNode<T> *curr = head;
			set<T> s;

			while (curr)
			{
				T val = curr->getData();
				if (s.find(val) != s.end())
				{
					if (prev)
					{
						SinglyNode<T> *next = curr->getNext();

						while (next && s.find(next->getData()) != s.end())
						{
							next = next->getNext();
						}

						prev->setNext(next);
					}
				}
				else
				{
					s.insert(val);
				}

				prev = curr;
				curr = curr->getNext();
			}

			return SinglyLinkedList<T>(head);
		}

		/**
			 * @brief Reverse linkedlist in one pass using 3 pointers.
			 * 
			 * @return void
			 */
		void reverse()
		{
			SinglyNode<T> *curr = head;
			SinglyNode<T> *prev = nullptr;
			SinglyNode<T> *next = nullptr;

			while (curr != nullptr)
			{
				next = curr->getNext();
				curr->setNext(prev);

				prev = curr;
				curr = next;
			}

			head = prev;
		}

		/**
			 * @brief Reverse linkedlist in one pass using 3 pointers.
			 * 
			 * @return SinglyNode
			 */
		SinglyNode<T> *reverse(SinglyNode<T> *head)
		{
			SinglyNode<T> *prev = nullptr;
			SinglyNode<T> *next = nullptr;
			SinglyNode<T> *curr = head;

			while (curr)
			{
				next = curr->getNext();
				curr->setNext(prev);

				prev = curr;
				curr = next;
			}

			return prev;
		}

		/**
			 * @brief Remove an element from SinglyLinkedList.
			 * 
			 * @param k 
			 * @return void
			 */
		void removeKFromList(T k)
		{
			this->head = removeKFromList(head, k);
		}

		/**
			 * @brief Treat linkedlist as a number an subtract one from it.
			 * 
			 * @return void
			 */
		void subtractOne()
		{
			subtractOneUtil(head);

			while (head && head->getNext() && head->getData() == 0)
			{
				head = head->getNext();
			}
		}

		/**
			 * @brief Get middle of linkedlist in one pass.
			 * 
			 * @return T
			 */
		T middle()
		{
			SinglyNode<T> *curr = head;
			SinglyNode<T> *middle = head;
			int length = 0;

			while (curr->getNext())
			{
				length++;
				if (length % 2 == 0)
				{
					middle = middle->getNext();
				}

				curr = curr->getNext();
			}

			if (length % 2 == 1)
			{
				middle = middle->getNext();
			}

			return middle->getData();
		}

		/**
		 * @brief Delete middle of linkedlist in one pass
		 * 
		 */
		void deleteMiddle()
		{
			if (this->head && !this->head->next) {
				head = nullptr;
				return;
			}

			SinglyNode<T> *curr = this->front();
			SinglyNode<T> *middle = this->front();
			SinglyNode<T> *prev = nullptr;

			int length = 0;

			while (curr->getNext()) {
				length++;

				if (length % 2 == 0) {
					prev = middle;
					middle = middle->getNext();
				}

				curr = curr->getNext();
			}

			if (length % 2 == 1) {
				prev = middle;
				middle = middle->getNext();
			}

			if (middle) {
				if (prev) {
					prev->setNext(middle->getNext());
				}

				delete middle;
			}
		}

		/**
			 * @brief Odd-even list.
			 * @example Input: head = [1,2,3,4,5]
			 *          Output: [1,3,5,2,4]
			 * 
			 * @return void
			 */
		SinglyLinkedList<T> oddEvenList()
		{
			SinglyNode<T> *even = nullptr;
			SinglyNode<T> *odd = this->oddEvenRecv(head, &even);
			even = this->reverse(even);

			SinglyNode<T> *temp = odd;
			if (temp)
			{
				while (temp->getNext())
				{
					temp = temp->getNext();
				}

				temp->setNext(even);

				return SinglyLinkedList<T>(odd);
			}
			else
			{
				return SinglyLinkedList<T>(even);
			}

			return SinglyLinkedList<T>();
		}

		/**
			 * @brief Get length of linkedlist.
			 * 
			 * @return int
			 */
		int length()
		{
			SinglyNode<T> *curr = head;
			int len = 0;

			while (curr)
			{
				curr = curr->getNext();
				len++;
			}

			return len;
		}

		/**
			 * @brief Given the head of a linked list, rotate the list to the right by k places.
			 * 
			 * @param k 
			 * @return SinglyNode<T>* 
			 */
		SinglyNode<T> *rotate(int k)
		{
			if (head == nullptr)
				return head;
			int len = this->length();

			for (int i = 0; i < (k % len); i++)
			{
				SinglyNode<T> *newHead = nullptr;
				SinglyNode<T> *headTemp = rotate(head, &newHead);
				newHead->setNext(headTemp);

				head = newHead;
			}

			return head;
		}

		/**
		 * @brief Given the head of a linked list, rotate the list to the left by k places.
		 * 
		 * @param k
		 * @return SinglyNode<T>*
		 * 
		 */
		SinglyNode<T>* rotateLeft(int k)
		{
			long len = this->count();
			if (k % len == 0)
			{
				return this->front();
			}

			// 1 -> 2 -> 3, k = 1
			// temp = 1, list = 2 -> 3
			// 
			//
			// list -> temp;
			// 2 -> 3 -> 1

			SinglyNode<T>* curr = this->front();
			SinglyNode<T>* temp = new SinglyNode<T>(curr->getData());
			SinglyNode<T>* curr2 = temp;

			if (k % len > 1){
				curr = curr->getNext();

				for (int i = 1; i < (k % len); i++)
				{
					SinglyNode<T>* t = new SinglyNode<T>(curr->getData());
					t->setNext(nullptr);

					curr2->setNext(t);

					curr2 = curr2->getNext();
					curr = curr->getNext();
				}
			} else {
				curr = curr->getNext();
			}

			// - link the right linkedlist with left linkedlist
			SinglyNode<T>* head2 = curr;
			while (curr->getNext())
			{
				curr = curr->getNext();
			}

			curr->setNext(temp);

			return head2;
		}

		/**
			 * @brief return linkedlist as sum of two linkedlist using operator+.
			 * 
			 * @param l2 
			 * @return SinglyLinkedList<T> 
			 */
		SinglyLinkedList<T> operator+(SinglyLinkedList<T> &l2)
		{
			SinglyNode<T> *l3 = nullptr;
			SinglyNode<T> *curr3 = nullptr;
			SinglyNode<T> *curr1 = this->front();
			SinglyNode<T> *curr2 = l2.front();
			int carry = 0;

			while (curr1 && curr2)
			{
				int sum = curr1->getData() + curr2->getData() + carry;
				int digit = (sum % 10);
				carry = sum >= 10 ? 1 : 0;

				if (!l3)
				{
					l3 = new SinglyNode<T>(digit);
					curr3 = l3;
				}
				else
				{
					curr3->setNext(new SinglyNode<T>(digit));
					curr3 = curr3->getNext();
				}

				curr1 = curr1->getNext();
				curr2 = curr2->getNext();
			}

			while (curr1)
			{
				int sum = curr1->getData() + carry;
				int digit = (sum % 10);
				carry = sum >= 10 ? 1 : 0;

				if (!l3)
				{
					l3 = new SinglyNode<T>(digit);
					curr3 = l3;
				}
				else
				{
					curr3->setNext(new SinglyNode<T>(digit));
					curr3 = curr3->getNext();
				}

				curr1 = curr1->getNext();
			}

			while (curr2)
			{
				int sum = curr2->getData() + carry;
				int digit = (sum % 10);
				carry = sum >= 10 ? 1 : 0;

				if (!l3)
				{
					l3 = new SinglyNode<T>(digit);
					curr3 = l3;
				}
				else
				{
					curr3->setNext(new SinglyNode<T>(digit));
					curr3 = curr3->getNext();
				}

				curr2 = curr2->getNext();
			}

			if (carry > 0)
			{
				curr3->setNext(new SinglyNode<T>(1));
			}

			SinglyLinkedList<T> ll3 = SinglyLinkedList(l3);
			return ll3;
		}

		/**
			 * @brief return linkedlist as a result of swapped nodes of kth node from beginning and
			 * and the kth node from the end.
			 * 
			 * @param k index of LinkedList
			 * @return SinglyLinkedList<T> LinkedList after swapping
		*/
		void swapNodesPosition(int k) {
			SinglyNode<T> *fast = this->head;
			SinglyNode<T> *slow = this->head;
			SinglyNode<T> *curr = this->head;
			SinglyNode<T> *prevC = nullptr;
			SinglyNode<T> *prev = nullptr;

			int i = 1;

			while (fast->getNext()) {
				fast = fast->getNext();

				if (i >= k) {
					prev = slow;
					slow = slow->getNext();
				}

				if (i < k) {
					prevC = curr;
					curr = curr->getNext();
				}

				i++;
			}

			// Check if slow pointer is same as curr node pointer
			if (slow == curr) {
				return;
			}

			if (prevC) {
				prevC->setNext(slow);
			}

			if (prev) {
				prev->setNext(curr);
			}

			SinglyNode<T> *temp = slow->getNext();
			slow->setNext(curr->getNext());
			curr->setNext(temp);

			if (slow == head) {
				this->head = curr;
				return;
			}

			this->head = curr == this->head ? slow : this->head;
		}
};

int main(int argc, char const *argv[])
{
	SinglyLinkedList<int> list(1);
	list.push(2);
	list.push(3);
	list.push(4);
	
	cout << "Swapping nodes index-1 with index-2...\n" << endl;

	list.swapNodesPosition(2);
	SinglyNode<int> *node = list.front();
	while (node)
	{
		cout << node->getData() << " ";
		node = node->getNext();
	}
	
	return 0;
}
