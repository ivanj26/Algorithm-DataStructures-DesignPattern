#include <string>
#include <iostream>
#include <vector>

using namespace std;

string permutate(string s, int maxLen = 3, string answer = "")
{
	string answers;
	if (answer.length() == maxLen)
	{
		return answer + " ";
	}

	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		string leftSubStr = s.substr(0, i);
		string rightSubStr = s.substr(i + 1);
		string next = leftSubStr + rightSubStr;
		answers += permutate(next, maxLen, answer + c);
	}

	return answers;
}

vector<string> toVector(string s)
{
	string ss;
	vector<string> res;
	for (int i = 0; i < s.length(); i++)
	{
		char c = s.at(i);
		if (c != ' ')
		{
			ss += c;
		}
		else
		{
			res.push_back(ss);
			ss = "";
		}
	}

	return res;
}

int main(int argc, char const *argv[])
{
	string ans = permutate("ABCD", 2);
	vector<string> v = toVector(ans);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}
