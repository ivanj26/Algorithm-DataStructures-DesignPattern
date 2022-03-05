#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

// Problem set: https://www.hackerrank.com/challenges/cpp-maps/problem?isFullScreen=true

int main()
{
	map<string, int> m;
	int n, i = 0;

	cin >> n;

	while (i < n)
	{
		int oper, val;
		string key;

		cin >> oper;

		switch (oper)
		{
		case 1:
			cin >> key >> val;

			if (m.find(key) == m.end())
				m.insert(make_pair(key, val));
			else
				m[key] += val;
			break;
		case 2:
			cin >> key;
			m.erase(key);
			break;
		case 3:
			cin >> key;
			if (m.find(key) == m.end())
			{
				cout << 0 << endl;
			}
			else
			{
				cout << m[key] << endl;
			}
			break;
		default:
			break;
		}

		i++;
	}

	return 0;
}
