#include <deque>
#include <string>
#include <iostream>

using namespace std;

void execute(char oper, int val, deque<int> &q)
{
	switch (oper)
	{
	case '1':
		q.push_back(val);
		break;
	case '2':
		q.pop_front();
		break;
	case '3':
		cout << q.front() << endl;
		break;
	}
}

string ltrim(const string &str)
{
	string s(str);

	s.erase(
		s.begin(),
		find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

	return s;
}

string rtrim(const string &str)
{
	string s(str);

	s.erase(
		find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
		s.end());

	return s;
}

int main()
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */

	string ns;
	getline(cin, ns);

	int n = stoi(ns);

	deque<int> q;

	int i = 0;
	while (i < n)
	{
		string query;
		getline(cin, query);

		query = ltrim(rtrim(query));

		int val = 0;
		char operation = query.at(0);

		// - parsing value in string to integer
		if (operation == '1')
		{
			string v = query.substr(2, query.length() - 2);

			int j = 0;
			int k = 1;
			while (j < v.length())
			{
				char c = v.at(v.length() - 1 - j);
				int _val = c - '0';

				val += (_val * k);

				j++;
				k *= 10;
			}
		}

		execute(operation, val, q);

		i++;
	}

	return 0;
}
