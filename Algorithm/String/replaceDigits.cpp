#include <string>
using namespace std;

class Solution {
	public:
		string replaceDigits(string s) {
			char even, odd;

			for (int i = 0; i < s.length(); i++) {
				if (i % 2 == 1) {
					odd = s.at(i);

					int shiftNum = odd - '0';
					s[i] = even + shiftNum;
				} else {
					even = s.at(i);
				}
			}

			return s;
		}
};