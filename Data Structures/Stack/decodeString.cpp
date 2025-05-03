#include <string>
#include <sstream>

using namespace std;

class Solution {
    private:
        string decodeStringUtil(string s, int &i) {
            stringstream ss;

            while (i < s.length()) {
                char c = s[i];
                if (c == '[') {
                    //skip it
                    i++;
                } else if (isdigit(c)) {
                    int n = 0;

                    // lets count
                    while (i < s.length() && isdigit(c)) {
                        n = (n * 10) + (c - '0');
                        c = s[++i];
                    }

                    string decodedChild = decodeStringUtil(s, i);
                    i++;

                    while (n-- > 0) {
                        ss << decodedChild;
                    }
                } else if (c == ']') {
                    break;
                } else { // if c is alphabet
                    ss << c;
                }
            }

            return ss.str();
        }
    public:
        string decodeString(string s) {
            int i = 0;
            return decodeStringUtil(s, i);
        }
};