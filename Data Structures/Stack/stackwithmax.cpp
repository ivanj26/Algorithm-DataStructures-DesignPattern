#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Stack with max element
class Stack
{
	private:
		int max;
		int *arr;
		int top;
		int MAX_SIZE;

	public:
		Stack()
		{
			MAX_SIZE = 10;

			arr = (int *)malloc(MAX_SIZE * sizeof(int));
			top = 0;
			max = -99;
		}

		~Stack()
		{
			delete[] arr;
		}

		//If sufficient, push to top
		//Else, realloc some space, and push
		void push(int val)
		{
			if (top < this->MAX_SIZE)
			{
				arr[top++] = val;
			}
			else
			{
				MAX_SIZE += 10;
				arr = (int *)realloc(arr, MAX_SIZE * sizeof(int));

				arr[top++] = val;
			}

			if (val > max)
				max = val;
		}

		//Pop element if element exist
		int pop()
		{
			if (top > 0)
			{
				int val = arr[--top];
				if (val == max)
				{
					max = -99;
					for (int i = 0; i < top; i++)
					{
						if (arr[i] > max)
							max = arr[i];
					}
				}
				return val;
			}
			return -1;
		}

		//Print max
		void printMax()
		{
			cout << max << endl;
		}
};

int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int n;
	cin >> n;

	Stack s;
	while (n > 0)
	{
		int code;
		cin >> code;

		switch (code)
		{
		case 1:
			int val;
			cin >> val;

			s.push(val);
			break;
		case 2:
			s.pop();
			break;
		default:
			s.printMax();
		}
		n--;
	}
	return 0;
}
