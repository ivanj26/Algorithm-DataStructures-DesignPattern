#include <stack>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class RPNCalculator {
    private:
        stack<double> st;
        stack< stack<double> > undoStack;
        stack< stack<double> > redoStack; 

        bool isOperator(string &t) {
            if (t.length() != 1) {
                return false;
            }

            return t.length() == 1 && (t[0] == '*' || t[0] == '/' || t[0] == '-' || t[0] == '+');
        }

        void calc(string oper) {
            char op = oper[0];

            double operand = st.top();
            st.pop();

            double operand2 = st.top();
            st.pop();
            
            double sum;

            switch (op)
            {
                case '+':
                    sum = operand2 + operand;
                    break;
                
                case '-':
                    sum = operand2 - operand;
                    break;

                case '/':
                    sum = operand2 / operand;
                    break;

                case '*':
                    sum = operand2 * operand;
                    break;

                default:
                    break;
            }

            st.push(sum);
        }

        double toNumber(string s) {
            double x = 0;
            int i = 0;

            while (i < s.length()) {
                x = (x * 10) + (s[i] - '0');
                i++;
            }

            return x;
        }

        void saveState() {
            undoStack.push(st);
            while (!redoStack.empty()) {
                redoStack.pop();
            }
        }

        void undo() {
            if (!undoStack.empty()) {
                redoStack.push(st);
                st = undoStack.top();
                undoStack.pop();

                while (st.size() > 1) {
                    st.pop();
                }
            }
        }

        void redo() {
            if (!redoStack.empty()) {
                undoStack.push(st);
                st = redoStack.top();
                redoStack.pop();
            }
        }

        bool isDigit(string s) {
            int i = 0;
            int sign = 1;

            if (s[i] == '-') {
                sign = -1;
                i++;
            }

            
            while (i < s.length()) {
                if (!isdigit(s[i])) {
                    return false;
                }

                i++;
            }

            return true;
        }

    public:
        double evalRPN(vector<string> &tokens) {
            for (string tok : tokens) {
                if (tok.length() < 1) {
                    continue;
                }
                
                if (tok == "undo") {
                    undo();
                } else if (tok == "redo") {
                    redo();
                } else {
                    if (isOperator(tok)) {
                        saveState();
                        calc(tok);
                        continue;
                    }

                    if (isDigit(tok)) {
                        st.push(toNumber(tok));
                        continue;
                    }
                }
            }

            return st.top();
        }
};

int main() {
    RPNCalculator calculator;
    vector<string> v = {"3", "2", "/", "5", "*", "undo", "redo", "undo"};

    cout << calculator.evalRPN(v) << endl;

    return 0;
}