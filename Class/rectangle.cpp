/**
 * File   : rectangle.cpp
 * Author : Ivan Jonathan
 **/

#include <iostream>
using namespace std;

class Rectangle
{
	private:
		double side;

	public:
		Rectangle(double _side) : side(_side) {}
		Rectangle() : side(0) {}
		double getArea()
		{
			return this->side * this->side;
		}
};

int main(int argc, char const *argv[])
{
	Rectangle r(5);
	cout << r.getArea() << endl;

	return 0;
}
