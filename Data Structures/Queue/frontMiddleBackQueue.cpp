#include <iostream>
#include <cstdlib>

using namespace std;

// Example 1:

// Input:
// ["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
// [[], [1], [2], [3], [4], [], [], [], [], []]

// Output:
// [null, null, null, null, null, 1, 3, 4, 2, -1]

class FrontMiddleBackQueue {
    private:
        int headPointer;
        int tailPointer;
        int midPointer;
        int *v;
        int size = 10;

        bool isEmpty() {
            return headPointer == -1 && tailPointer == -1 && midPointer == -1;
        }

        bool isFull() {
            return tailPointer == (size - 1);
        }

        void reallocIfFull() {
            if (this->isFull()) {
                size += 10;
                v = (int*) realloc(v, size * sizeof(int));
                if (v == nullptr) {
                    cout << "Realloc is failed!" << endl;
                    exit(-1);
                }
            }
        }

        void print() {
            for (int i = 0; i <= tailPointer; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    public:
        FrontMiddleBackQueue() {
            headPointer = -1;
            tailPointer = -1;
            midPointer = -1;

            v = (int*) malloc(size*sizeof(int));
        }
        
        void pushFront(int val) {
            this->reallocIfFull();
            if (this->isEmpty()) {
                v[++headPointer] = val;

                tailPointer++;
                midPointer++;
            } else {
                // Move all elements to right by 1 step
                for (int i = tailPointer + 1; i > 0; i--) {
                    v[i] = v[i-1];
                }

                v[0] = val;
                tailPointer++;
                midPointer = tailPointer / 2;
            }
        }
        
        void pushMiddle(int val) {
            this->reallocIfFull();

            if (this->isEmpty()) {
                headPointer++;
                tailPointer++;

                v[++midPointer] = val;
            } else {
                tailPointer++;
                for (int i = tailPointer; i > midPointer; i--) {
                    v[i] = v[i-1];
                }
                midPointer = tailPointer / 2;
                v[midPointer] = val;
            }
        }
        
        void pushBack(int val) {
            this->reallocIfFull();
            
            if (this->isEmpty()) {
                headPointer++;
                midPointer++;
            }

            v[++tailPointer] = val;
            midPointer = tailPointer / 2;
        }
        
        int popFront() {
            if (this->isEmpty()) {
                return -1;
            }

            int front = v[0];
            for (int i = 0; i < tailPointer; i++) {
                v[i] = v[i+1];
            }

            tailPointer--;
            if (tailPointer < 0) {
                midPointer = -1;
                headPointer = -1;
            } else {
                midPointer = tailPointer / 2;
            }

            return front;
        }
        
        int popMiddle() {
            if (this->isEmpty()) {
                return -1;
            }

            int mid = v[midPointer];
            for (int i = midPointer; i < tailPointer; i++) {
                v[i] = v[i+1];
            }
            
            tailPointer--;
            if (tailPointer < 0) {
                midPointer = -1;
                headPointer = -1;
            } else {
                midPointer = tailPointer / 2;
            }

            return mid;
        }
        
        int popBack() {
            if (this->isEmpty()) {
                return -1;
            }

            int back = v[tailPointer];
            tailPointer--;

            if (tailPointer < 0) {
                midPointer = -1;
                headPointer = -1;
            } else {
                midPointer = tailPointer / 2;
            }
            return back;
        }
};

int main () {
    return 0;
}

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */