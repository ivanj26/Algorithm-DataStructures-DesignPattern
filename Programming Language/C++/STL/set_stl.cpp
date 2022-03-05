#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// Problem set: https://www.hackerrank.com/challenges/cpp-sets/problem?isFullScreen=true

int main()
{
	set<int> s;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int oper, num;
		cin >> oper >> num;

		switch (oper)
		{
		case 1:
			s.insert(num);
			break;
		case 2:
			s.erase(num);
			break;
		case 3:
			if (s.find(num) != s.end())
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
			break;
		}
	}

	return 0;
}
