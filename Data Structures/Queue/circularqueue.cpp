#include <iostream>
using namespace std;

class CircularQueue
{
	private:
		int *arr;
		int p_head;
		int p_tail;
		int size;

	public:
		CircularQueue(int k) : size(k), p_head(-1), p_tail(-1)
		{
			arr = new int[k];
		}

		bool isFull()
		{
			return (p_head == 0 && p_tail == size - 1) || (p_head - 1 == p_tail);
		}

		bool isEmpty()
		{
			return p_head == -1 && p_tail == -1;
		}

		bool enQueue(int value)
		{
			if (this->isFull())
			{
				cout << "queue is full!" << endl;
				return false;
			}

			if (p_tail == size - 1 && p_head != 0)
			{
				p_tail = 0;
				arr[p_tail] = value;
			}
			else if (p_head == -1)
			{
				p_head = p_tail = 0;
				arr[p_tail] = value;
			}
			else
			{
				p_tail++;
				arr[p_tail] = value;
			}

			return true;
		}

		bool deQueue()
		{
			if (this->isEmpty())
			{
				cout << "queue is empty!" << endl;
				return false;
			}

			// - set -1
			arr[p_head] = -1;

			if (p_head == p_tail)
			{
				p_head = p_tail = -1;
			}
			else if (p_head == size - 1)
			{
				p_head = 0;
			}
			else
			{
				p_head++;
			}

			return true;
		}

		int front()
		{
			return p_head != -1 ? arr[p_head] : -1;
		}

		int rear()
		{
			return p_tail != -1 ? arr[p_tail] : -1;
		}

		void print()
		{
			for (int i = 0; i <= size - 1; i++)
			{
				if (i < size - 1)
				{
					cout << arr[i] << ' ';
				}
				else
				{
					cout << arr[i] << endl;
				}
			}
		}
};

int main(int argc, char const *argv[])
{
	CircularQueue c(3);
	c.enQueue(1);
	c.enQueue(2);
	c.enQueue(3);
	c.enQueue(4);

	c.deQueue();
	c.enQueue(5);
	c.deQueue();
	c.deQueue();
	c.deQueue();
	c.deQueue();
	c.enQueue(10);

	c.print();
	return 0;
}
