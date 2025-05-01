#include <string>
#include <sstream>
#include <stack>
#include <algorithm>

using namespace std;

// Input: s = "leet**cod*e"
// Output: "lecoe"
// Explanation: Performing the removals from left to right:
// - The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
// - The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
// - The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".

class Solution {
    public:
        string removeStars(string s) {
            stack<char> st;
    
            int i = 0;
            while (i < s.length()) {
                char c = s[i];
                if (c == '*') {
                    // Do pop if stack is not empty
                    if (!st.empty()) {
                        st.pop();
                    }
                } else {
                    st.push(c);
                }
                i++;
            }
    
            stringstream ss;
            while (!st.empty()) {
                ss << st.top();
                st.pop();
            }
    
            string out = ss.str();
            reverse(out.begin(), out.end());
    
            return out;
        }
    };