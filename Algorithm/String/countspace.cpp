#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	stack<char> st;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		char c = s.at(i);
		if (c == ' ')
		{
			st.push(c);
		}
	}

	cout << st.size() << endl;

	return 0;
}
