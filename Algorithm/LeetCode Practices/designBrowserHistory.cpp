#include <string>

using namespace std;

struct DoublyNode {
	DoublyNode *next;
	DoublyNode *prev;
	string url;

	DoublyNode(string url)
	{
		this->url = url;
		this->prev = nullptr;
		this->next = nullptr;
	}
};

struct DoublyLinkedList {
	DoublyNode *head;

	DoublyLinkedList(DoublyNode *head)
	{
		this->head = head;
	}
};

class BrowserHistory {
	private:
		DoublyLinkedList *dl;
		DoublyNode *curr;
		int history;

	public:
		BrowserHistory(string homepage)
		{
			curr = new DoublyNode(homepage);

			dl = new DoublyLinkedList(curr);
			history = 1;
		}

		~BrowserHistory()
		{
			delete dl;
		}

		void visit(string url)
		{
			if (!this->dl->head)
			{
				dl->head = new DoublyNode(url);
				curr = dl->head;
			}
			else
			{
				if (curr->next)
				{
					int count = 0;
					DoublyNode *curr2 = curr->next;

					while (curr2)
					{
						count++;
						curr2 = curr2->next;
					}

					history -= count;
				}

				DoublyNode *prev = curr;
				curr->next = new DoublyNode(url);

				curr = curr->next;
				curr->prev = prev;
			}

			history++;
		}

		string back(int steps)
		{
			if (history <= steps)
			{
				steps = history - 1;
			}

			DoublyNode *next = nullptr;
			int i;
			for (i = 0; i < steps && curr; i++)
			{
				next = curr;
				curr = curr->prev;
			}

			if (!curr)
			{
				curr = next;
			}

			return curr->url;
		}

		string forward(int steps)
		{
			int i = 0;
			DoublyNode *prev = nullptr;

			while (curr && i < steps)
			{
				prev = curr;
				curr = curr->next;
				i++;
			}

			if (!curr)
			{
				curr = prev;
			}

			return curr->url;
		}
};