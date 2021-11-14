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

#include <iostream>
#include <string>
using namespace std;

class Solution {
    private:
        int calc(int a, int b, char oper = '+')
        {
            return oper == '+'
                ? a + b
                : a - b;
        }

        int calculateHelper(string s, int &i)
        {
            int ans = 0;
            char oper = '+';

            while (i < s.length())
            {
                char c = s[i];

                switch (c) {
                case '-':
                case '+': {
                    oper = c;
                    break;
                }
                case '(': {
                    int temp = calculateHelper(s, ++i);
                    ans = calc(ans, temp, oper);
                    break;
                }
                case ')': {
                    return ans;
                }
                default:
                    if (isdigit(c))
                    {
                        int digit = 0;

                        while (isdigit(c))
                        {
                            digit *= 10;
                            digit += (c - '0');
                            c = s[++i];
                        }

                        i--;
                        ans = calc(ans, digit, oper);
                    }
                    break;
                }

                i++;
            }

            return ans;
        }

    public:
        int calculate(string s)
        {
            int i = 0;
            return calculateHelper(s, i);
        }
};

int main(int argc, char const *argv[])
{
    Solution s;

    cout << "-(3 + ( 5 - 7)):\t";
    cout << s.calculate("-(3 + ( 5 - 7))") << endl;
    return 0;
}
