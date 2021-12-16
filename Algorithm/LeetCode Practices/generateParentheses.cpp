/**
 * @file generateParentheses.cpp
 * @author Ivan
 * @brief 
 * @version 0.1
 * @date 2021-12-16
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
	private:
		void addingParenth(vector<string> &v, string str, int n, int m)
		{
			if (n == 0 && m == 0)
			{
				// enter this condition
				// if open and close bracket quota is empty
				v.push_back(str);
				return;
			}

			if (m > 0) {
				// adding close bracket to str
				addingParenth(v, str + ")", n, m-1);
			}

			if (n > 0) {
				// adding open bracket to str
				addingParenth(v, str + "(", n - 1, m + 1);
			}
		}
	public:
		vector<string> generateParentheses(int n)
		{
			vector<string> res;

			addingParenth(res, "", n, 0);
			
			return res;
		}
};

int main(int argc, char const *argv[])
{
	Solution sol;
	vector<string> result = sol.generateParentheses(2);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
		cout << " ";
	}
	cout << endl;

	return 0;
}
