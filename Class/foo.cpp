/**
 * File   : foo.cpp
 * Author : Ivan Jonathan
 **/

#include <iostream>
using namespace std;

class Foo
{
	private:
		int x;
		int y;

	public:
		Foo(int _x, int _y) : x(_x), y(_y)
		{
			int sum = x + y;

			cout << sum << endl;
		}
};

int main(int argc, char const *argv[])
{
	Foo f(10, 20);
	return 0;
}
