#include <vector>
#include <stack>

using namespace std;

// temperatures = [73,74,75,71,69,72,72,73] // 8 elements
        
// 1. Initialize the variables:
//    - Create the output array with a same length as our input array (Set the default value with 0)
//      `res` = [0,0,0,0,0,0,0,0]
//       st = [] // store the element with type of `Item`

// 2. Iterating our input array starting from the last element to first element
//    currPos = temperature.size() - 1
//    res[currPos] = 0 // set the output for our last element
//    st = [Item(7, 73)]
//    currPos--;

//    while the stack is not empty
//       if currVal >= st.top().val then
//          st.pop() 
// 
//    if stack is not empty
//       Set the output with a formula (top element's index - current position/index)
//       res[currPos] = st.top().idx - currPos
//
//    Push the current element into stack, it will be used for the previous element
//    st.push()

struct Item {
    int idx;
    int val;
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<Item> st;

        // Our current position will be starting from the last element
        int currPos = temperatures.size() - 1;
        st.push(Item(currPos, temperatures[currPos]));

        currPos--;

        while (currPos >= 0) {
            int currVal = temperatures[currPos];
            while (!st.empty() && currVal >= st.top().val) {
                st.pop();
            }

            if (!st.empty()) {
                res[currPos] = st.top().idx - currPos;
            }

            st.push(Item(currPos, currVal));
            currPos--;
        }

        return res;
    }
};