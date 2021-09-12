#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
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
        /**
         * @brief Construct a new Stack object
         * 
         */
        Stack() : MAX_SIZE(10), top(0), max(-99)
        {
            arr = (int *)malloc(sizeof(int) * MAX_SIZE);
        }

        /**
         * @brief Destroy the Stack object
         * 
         */
        ~Stack()
        {
            delete[] arr;
        }

        /**
         * @brief Push new value into top of stack. Stack will updating the max value and realloc when its reach the max of capacity.
         * 
         * @param val 
         * @return void
         */
        void push(int val)
        {
            if (top < this->MAX_SIZE)
            {
                arr[top++] = val;
            }
            else
            {
                MAX_SIZE += 10;
                arr = (int *)realloc(arr, sizeof(int) * MAX_SIZE);
                arr[top++] = val;
            }

            if (val > max)
                max = val;
        }

        /**
         * @brief Pop top element if stack is not empty.
         * 
         * @return int 
         */
        int pop()
        {
            if (top > 0)
            {
                // - flag if already popped out
                arr[top - 1] = -999;

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

        /**
         * @brief Print the max value of stack.
         * 
         * @return void
         */
        void printMax()
        {
            cout << max << endl;
        }

        /**
         * @brief Print all of elements from top to bottom of stack.
         * 
         * @return void
         */
        void print()
        {
            for (int i = top - 1; i >= 0; i--)
            {
                if (i == 0)
                {
                    cout << arr[0] << endl;
                }
                else
                {
                    cout << arr[i] << " ";
                }
            }
        }

        /**
         * @brief Check if string is valid parentheses.
         * 
         * @param s string
         * @return boolean 
         */
        bool isValid(string s)
        {
            // @TODO: change to own stack class instead of using the c++ STL library.
            stack<char> st;

            // if the length of string is odd
            // then it is must be invalid
            if (s.length() % 2 == 1)
            {
                return false;
            }

            for (int i = 0; i < s.length(); i++)
            {
                char c = s.at(i);

                switch (c)
                {
                case '(':
                case '{':
                case '[':
                    st.push(c);
                    break;
                case '}':
                case ')':
                case ']':
                    if (!st.empty())
                    {
                        char top = st.top();

                        if (top == '(' && c == ')')
                        {
                            st.pop();
                        }
                        else if (top == '{' && c == '}')
                        {
                            st.pop();
                        }
                        else if (top == '[' && c == ']')
                        {
                            st.pop();
                        }
                        else
                        {
                            // if its not the pair
                            // we should treat it as invalid parentheses
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                    break;
                }
            }

            return st.empty() ? true : false;
        }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(3);
    s.push(-1);
    s.push(0);
    s.pop();

    s.print();
    return 0;
}
