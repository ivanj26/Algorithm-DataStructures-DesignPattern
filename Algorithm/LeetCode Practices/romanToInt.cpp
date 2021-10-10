#include <string>
#include <stack>
#include <iostream>
#include <unordered_map>

using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> map;
    stack<char> st;

    map['I'] = 1;
    map['V'] = 5;
    map['X'] = 10;
    map['L'] = 50;
    map['C'] = 100;
    map['D'] = 500;
    map['M'] = 1000;

    for (int i = 0; i < s.length(); i++) {
        st.push(s.at(i));
    }

    int count = 0;
    char prev = ' ';

    while (!st.empty()) {
        char c = st.top();
        char sign = '+';
        int val = map[c];
        st.pop();

        switch (c) {
            case 'I':
                if (prev == 'X' || prev == 'V') {
                    sign = '-';
                }
                break;
            case 'X':
                if (prev == 'L' || prev == 'C') {
                    sign = '-';
                }
                break;
            case 'C':
                if (prev == 'D' || prev == 'M') {
                    sign = '-';
                }
                break;
            default:
                break;
        }

        prev = c;
        if (sign == '-') {
            count -= val;
        } else {
            count += val;
        }
    }

    return count;
}

int main(int argc, char const *argv[])
{
    cout << romanToInt("MCMXCIV") << endl;
    return 0;
}
