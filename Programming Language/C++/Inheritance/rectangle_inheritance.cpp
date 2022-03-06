#include <iostream>

using namespace std;

// Problem: https://www.hackerrank.com/challenges/rectangle-area/problem?isFullScreen=true

/*
 * Create classes Rectangle and InheritedRectangle
 */
class Rectangle
{
protected:
	int width;
	int height;

public:
	void display()
	{
		cout << width << " " << height << "\n";
	}

	void setWidth(int width)
	{
		this->width = width;
	}

	void setHeight(int height)
	{
		this->height = height;
	}
};

class InheritedRectangle : public Rectangle
{
public:
	void read_input()
	{
		cin >> width >> height;
	}

	void display()
	{
		int area = width * height;
		cout << area << endl;
	}
};

int main()
{
	/*
	 * Declare a InheritedRectangle object
	 */
	InheritedRectangle r_area;

	/*
	 * Read the width and height
	 */
	r_area.read_input();

	/*
	 * Print the width and height
	 */
	r_area.Rectangle::display();

	/*
	 * Print the area
	 */
	r_area.display();

	return 0;
}