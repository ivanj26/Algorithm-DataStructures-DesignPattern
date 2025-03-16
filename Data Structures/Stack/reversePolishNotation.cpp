#include <stack>
#include <vector>

// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.

class Solution {
    private:
        bool isoperator(string tok) {
            return tok.length() == 1 && (tok[0] == '+' || tok[0] == '*' || tok[0] == '/' || tok[0] == '-');
        }

        int toInt(string tok) {
            int sign = 1;
            int i = 0;
            if (tok[i] == '-') {
                sign = -1;
                i++;
            }

            int num = 0;
            while (i < tok.length()){
                num = (num * 10) + (tok[i] - '0');
                i++;
            }

            return sign == -1 ? -num : num;
        }

    public:
        int evalRPN(vector<string> &tokens) {
            stack<int> st;
            for (string token : tokens) {
                // If the string is digit
                if (!isoperator(token)) {
                    st.push(toInt(token));
                    
                    continue;
                }

                // If the string is operator
                char oper = token[0];
                int total = 0;

                int top = st.top();
                st.pop();

                int nextTop = 0;
                if (!st.empty()) {
                    nextTop = st.top();
                    st.pop();
                }

                switch (oper) {
                    case '+':
                        st.push(nextTop + top);
                        break;
                    case '-':
                        st.push(nextTop - top);
                        break;
                    case '*':
                        st.push(nextTop * top);
                        break;
                    case '/':
                        st.push(nextTop / top);
                        break;
                }
            }

            return st.top();
        }
};

// Constraints:

// 1 <= tokens.length <= 104
// tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

using namespace std;