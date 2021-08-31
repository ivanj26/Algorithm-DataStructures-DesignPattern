#include <stack>
#include <string>
#include <iostream>

using namespace std;

bool areBalancedBrackets(string expr)
{
	stack<char> s;

	for (int i = 0; i < expr.length(); i++)
	{
		char c = expr[i];
		if (c == '(')
		{
			s.push(c);
			continue;
		}

		if (s.empty())
		{
			return false;
		}

		if (c == ')')
		{
			char top = s.top();
			s.pop();
			if (top != '(')
			{
				return false;
			}
		}
	}

	return s.empty();
}

int reverseNumberUsingStack(int number)
{
	stack<int> s;

	while (number != 0)
	{
		s.push(number % 10);

		number = number / 10;
	}

	int i = 1;
	int reverseNumber = 0;

	while (!s.empty())
	{
		reverseNumber = reverseNumber + (i * s.top());
		s.pop();

		i = i * 10;
	}

	return reverseNumber;
}

int main(int argc, char const *argv[])
{
	string expr = "((ab)(bc)())";
	int number = 1460042;

	cout << areBalancedBrackets(expr) << endl;
	cout << reverseNumberUsingStack(number);
	return 0;
}
