// Open-Closed Principle
//
// The principle suggests that the class should be open for extension,
// but closed for modification.

#define _USE_MATH_DEFINES
#include <math.h>
#include <type_traits>
#include <iostream>
using namespace std;

// Let say, I have a Shape class which have a method to calculate the area.
template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
class RealShape {
    public:
        T calculateArea() {
            return 0;
        }
};

// To make it comply with the OCP principle.
// We need to create a specific class that implement their own `calculateArea()`
//
// For example:

template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
class Shape {
    public:
        virtual T calculateArea() = 0;
};

// Let say, i have 2 shapes:
// 1. Circle
// 2. Rectangle

// Circle class can inherit the Shape class
// and modify their base class method which is calculateArea() to its own formula.
template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
class Circle : public Shape<T> {
    public:
        T radius;

        Circle(T _radius) {
            this->radius = _radius;
        }

        T calculateArea() override {
            return M_PI * this->radius * this->radius;
        }
};


// Rectangle class can inherit the Shape class
// and modify their base class method which is calculateArea() to its own formula.
template <typename T, typename std::enable_if<std::is_arithmetic<T>::value, int>::type = 0>
class Rectangle : public Shape<T> {
    public:
        T height;
        T length;

        Rectangle(T _length, T _height) {
            this->length = _length;
            this->height = _height;
        }

        T calculateArea() override {
            return this->height * this->length;
        }
};

// g++ open_closed.cpp -o ocp.out
// ./ocp.out
int main(int argc, char const *argv[])
{
    Shape<float> *circle = new Circle<float>(25);
    std::cout << "Circle Area: " << circle->calculateArea() << std::endl;

    Shape<int> *rectangle = new Rectangle<int>(5, 6);
    std::cout << "Rectangle Area: " << rectangle->calculateArea() << std::endl; 


    delete circle;
    delete rectangle;

    return 0;
}


