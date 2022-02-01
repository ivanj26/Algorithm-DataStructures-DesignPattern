#include <string>

using namespace std;

class Solution {
	public:
		string multiply(string a, string b) {
			int n = a.length();
			int m = b.length();

			string res(n + m, '0');
			for (int i = n - 1; i >= 0; i--) {
				int first = a.at(i) - '0';

				for (int j = m - 1; j >= 0; j--) {
					int second = b.at(j) - '0';
					int count = (first * second) + (res[i + j + 1] - '0');
					res[i + j + 1] = (count % 10) + '0';
					res[i + j] = count / 10;
				}
			}

			for (int i = 0; i < res.length(); i++) {
				if (res[i] != '0') {
					return res.substr(i);
				}
			}

			return "0";
		}
};