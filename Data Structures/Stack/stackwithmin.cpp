#include <iostream>

using namespace std;

struct Node
{
	int data;
	int min;
	Node *next;
	Node *prev;
	Node(int v)
	{
		data = v;
		next = nullptr;
		prev = nullptr;
	}
};

/**
 * @brief Implement MinStack class with Doubly Linkedlist.
 * 
 */
class MinStack
{
	private:
		Node *currNode; // treat as top of stack

	public:
		/**
		 * @brief Construct a new Min Stack object
		 * 
		 */
		MinStack()
		{
			currNode = nullptr;
		}

		/**
		 * @brief Push new element to the top of stack.
		 * 
		 * @param val 
		 */
		void push(int val)
		{
			if (currNode == nullptr)
			{
				currNode = new Node(val);
				currNode->min = INT_MAX;
			}
			else
			{
				Node* next = new Node(val);
				next->prev = currNode;
				next->min = currNode->min > val ? val : currNode->min;

				currNode->next = next;
				currNode = currNode->next;
			}
		}

		/**
		 * @brief Pop the stack.
		 * 
		 */
		void pop()
		{
			Node* deleted = currNode;
			currNode = currNode->prev;

			delete deleted;
		}

		/**
		 * @brief Get top of stack value without popping out the top element.
		 * 
		 * @return int
		 */
		int top()
		{
			return currNode ? currNode->data : INT_MAX;
		}

		/**
		 * @brief Get the minimum value of current stack.
		 * 
		 * @return int 
		 */
		int getMin()
		{
			return currNode ? currNode->min : INT_MAX;
		}
};

int main(int argc, char const *argv[])
{
	MinStack s;
	s.push(3);
	s.push(-1);
	s.push(2);
	s.pop();
	s.push(1);

	cout << "Top of stack: " << s.top() << endl;
	cout << "Min of stack: " << s.getMin() << endl;

	return 0;
}
