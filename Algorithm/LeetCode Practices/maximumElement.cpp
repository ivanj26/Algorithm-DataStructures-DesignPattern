#include <vector>
#include <stack>
#include <iostream>
#include <string>

using namespace std;

vector<int> getMax(vector<string> operations)
{
	stack<int> st;
	vector<int> res;
	int max = INT_MIN;

	for (auto operation : operations)
	{
		char $_operator = operation.at(0);

		int val = 0;
		int i = 0;
		int j = 1;
		int top;
		string numbers;
		int length = 0;

		if ($_operator == '1')
		{
			numbers = operation.substr(2, operation.length() - 2);
			length = numbers.length();
		}

		if ($_operator == '2')
		{
			top = st.top();
		}

		switch ($_operator)
		{
		case '1':
			while (i < length)
			{
				char c = numbers.at(length - i - 1);
				int v = c - '0';

				val += (v * j);

				i++;
				j *= 10;
			}

			st.push(val);

			if (val > max)
			{
				max = val;
			}

			break;
		case '2':
			st.pop();

			if (top == max)
			{
				max = INT_MIN;

				stack<int> temp;
				while (!st.empty())
				{
					if (st.top() > max)
					{
						max = st.top();
					}

					temp.push(st.top());
					st.pop();
				}

				while (!temp.empty())
				{
					st.push(temp.top());
					temp.pop();
				}
			}

			break;
		case '3':
			// print the max
			cout << max << endl;

			res.push_back(max);
			break;
		}
	}

	return res;
}