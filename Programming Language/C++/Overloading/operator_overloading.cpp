#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Problem: https://www.hackerrank.com/challenges/operator-overloading/problem?isFullScreen=true

class Matrix {
	public:
		vector<vector<int>> a;

		friend Matrix operator+(Matrix &m1, Matrix &m2)
		{
			Matrix res;
			int n = m1.a.size();

			for (int i = 0; i < n; i++)
			{
				vector<int> b1 = m1.a[i];
				vector<int> b2 = m2.a[i];

				std::transform(b1.begin(), b1.end(), b2.begin(), b1.begin(), std::plus<int>());

				res.a.push_back(b1);
			}

			return res;
		}
};

int main()
{
	int cases, k;
	cin >> cases;
	for (k = 0; k < cases; k++)
	{
		Matrix x;
		Matrix y;
		Matrix result;
		int n, m, i, j;
		cin >> n >> m;
		for (i = 0; i < n; i++)
		{
			vector<int> b;
			int num;
			for (j = 0; j < m; j++)
			{
				cin >> num;
				b.push_back(num);
			}
			x.a.push_back(b);
		}
		for (i = 0; i < n; i++)
		{
			vector<int> b;
			int num;
			for (j = 0; j < m; j++)
			{
				cin >> num;
				b.push_back(num);
			}
			y.a.push_back(b);
		}
		result = x + y;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << result.a[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
