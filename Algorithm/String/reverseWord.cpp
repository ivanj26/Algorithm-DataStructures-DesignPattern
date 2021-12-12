#include <string>
#include <vector>
#include <iostream>

using namespace std;

string reverseWord(string s)
{
	vector<string> v;

	string temp;
	int length = s.length();
	for (int i = 0; i < length; i++)
	{
		char c = s[i];

		if (c == ' ')
		{
			if (temp.length() > 0)
			{
				v.push_back(temp);
				temp = "";
				continue;
			}

			continue;
		}

		temp += c;

		bool isLast = i == length - 1;
		if (isLast)
		{
			v.push_back(temp);
		}
	}

	string res;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (i > 0)
		{
			res += (v[i] + " ");
		}
		else
		{
			res += v[i];
		}
	}

	return res;
}

int main(int argc, char const *argv[])
{
	cout << reverseWord("Hello world") << endl;
	return 0;
}
