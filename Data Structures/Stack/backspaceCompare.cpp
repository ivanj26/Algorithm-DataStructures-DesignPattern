#include <stack>
#include <string>

using namespace std;

class Solution {
	bool checkIfSame(stack<char> &s1, stack<char>& s2) {
		while (!s1.empty()) {
			int v1 = s1.top();
			int v2 = s2.top();
			
			if (v2 != v1) {
				return false;
			}
			
			s1.pop();
			s2.pop();
		}
		
		return true;
	}
	
public:
	bool backspaceCompare(string s, string t) {
		stack<char> st1;
		stack<char> st2;
		
		for (int i = 0; i < s.length(); i++) { 
			if (s[i] != '#') {
				st1.push(s[i]);
			} else {
				if (!st1.empty()) st1.pop();
			}
		}
		
		for (int i = 0; i < t.length(); i++) { 
			if (t[i] != '#') {
				st2.push(t[i]);
			} else {
				if (!st2.empty()) st2.pop();
			}
		}
		
		return st1.size() == st2.size() ? checkIfSame(st1, st2) : false;
	}
};