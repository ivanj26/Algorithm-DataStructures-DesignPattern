/**
 * @file calculator.cpp
 * @author Ivan Jonathan
 * @brief calculate / evaluate mathmetical expression in string.
 * @version 0.1
 * @date 2021-11-14
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <string>
#include <iostream>

using namespace std;

enum Character
{
	PLUS = '+',
	MINUS = '-',
	OPEN_BRACKET = '(',
	CLOSE_BRACKET = ')'
};

class Calculator
{
	private:
		int calc(int a, int b, char oper = Character::PLUS)
		{
			return oper == Character::PLUS
					? a + b
					: a - b;
		}

		int calculateHelper(string s, int &i)
		{
			int ans = 0;
			char oper = Character::PLUS;

			while (i < s.length())
			{
				char c = s.at(i);

				switch (c)
				{
				case Character::MINUS:
				case Character::PLUS:
				{
					oper = c;
					break;
				}
				case Character::OPEN_BRACKET:
				{
					int temp = this->calculateHelper(s, ++i);
					ans = this->calc(ans, temp, oper);
					break;
				}
				case Character::CLOSE_BRACKET:
				{
					// base recursive
					return ans;
				}
				default:
				{
					if (isdigit(c))
					{
						int base = 10;
						int digit = 0;

						while (isdigit(c))
						{
							digit *= base;
							digit += (c - '0');

							c = s.at(++i);
						}

						i--;
						ans = this->calc(ans, digit, oper);
					}
					break;
				}
				}

				i++;
			}

			return ans;
		}

	public:
		int calculate(string s)
		{
			int i = 0;
			return this->calculateHelper(s, i);
		}
};

int main(int argc, char const *argv[])
{
	Calculator obj;
	int result = obj.calculate("(245 - (3 + 2 - 1))");

	cout << result << endl;

	return 0;
}
