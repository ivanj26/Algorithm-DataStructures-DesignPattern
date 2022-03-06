#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

// Problem: https://www.hackerrank.com/challenges/c-class-templates/problem

template <class T>
class AddElements {
	private:
		T val;

	public:
		AddElements(T t)
		{
			this->val = t;
		}

		T add(T t)
		{
			return this->val + t;
		}
};

template <> class AddElements<string> {
	public:
		AddElements(string el)
		{
			this->el = el;
		}
		string concatenate(string el2)
		{
			return el + el2;
		}

	private:
		string el;
};

int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		string type;
		cin >> type;
		if (type == "float")
		{
			double element1, element2;
			cin >> element1 >> element2;
			AddElements<double> myfloat(element1);
			cout << myfloat.add(element2) << endl;
		}
		else if (type == "int")
		{
			int element1, element2;
			cin >> element1 >> element2;
			AddElements<int> myint(element1);
			cout << myint.add(element2) << endl;
		}
		else if (type == "string")
		{
			string element1, element2;
			cin >> element1 >> element2;
			AddElements<string> mystring(element1);
			cout << mystring.concatenate(element2) << endl;
		}
	}
	return 0;
}
