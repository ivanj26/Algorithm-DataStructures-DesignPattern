#include <stack>

using namespace std;

class MyQueue {
    private:
        stack<int> stackNewestOnTop;
        stack<int> stackOldestOnTop;
    public:
        void push(int val) {
            stackNewestOnTop.push(val);
        }

        void prepOld() {
            if (stackOldestOnTop.empty()) {
                while (!stackNewestOnTop.empty()) {
                    stackOldestOnTop.push(stackNewestOnTop.top());
                    stackNewestOnTop.pop();
                }
            }
        }

        void prepNew() {
            if (stackNewestOnTop.empty()) {
                while (!stackOldestOnTop.empty()) {
                    stackNewestOnTop.push(stackOldestOnTop.top());
                    stackOldestOnTop.pop();
                }
            }
        }
        
        int front() {
            prepOld();
            return stackOldestOnTop.top();
        }

        void pop() {
            prepOld();
            stackOldestOnTop.pop();
            prepNew();
        }
};

int main(int argc, char const *argv[])
{
    return 0;
}
