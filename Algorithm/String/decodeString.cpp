#include <iostream>
#include <string>

using namespace std;

// not optimize solution yet
string recv(string s)
{
	int loop = 0;
	bool isPrevDigit = false;

	string res;

	for(int i = 0; i < s.length(); i++) {
		char c = s.at(i);

		if (isdigit(c)) {
			if (isPrevDigit) {
				while (isdigit(c)) {
					loop += 10;
					loop += (c - '0');
					c = s.at(++i);
				}

				i--;
				isPrevDigit = false;
			} else {
				loop = c - '0';
				isPrevDigit = true;
			}
		} else {
			isPrevDigit = false;

			// if non-digit character
			if (c == '[') {
				string rep;

				for (int j = 0; j < loop; j++) {
					rep = recv(s.substr(i + 1));

					res += rep;
				}

				i += (rep.length() + 1);
			} else if (c == ']') {
				// base recursive
				return res;
			} else {
				res.push_back(c);
			}
		}
	}

	return res;
}