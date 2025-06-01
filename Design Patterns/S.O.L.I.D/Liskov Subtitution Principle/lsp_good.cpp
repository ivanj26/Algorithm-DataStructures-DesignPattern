#include <iostream>
using namespace std;

// Good example of LSP
// 1. Square and Rectangle are best / proper replacement for Shape class because they have their own formulas 
// on how to calculate the area.

// 2. Shape itself is more general term. It means their subclass has a flexbility to decide the area formula.
//    It does not break the logic of the application


class Shape { // Shape interface and requires the subclass to implement the method "calculateArea"
    public:
        virtual long calculateArea() = 0;
};

class Rectangle : public Shape {
    private:
        int height;
        int width;
    public:
        Rectangle() {

        }

        Rectangle(int h, int w) {
            this->height = h;
            this->width = w;
        }

        void setHeight(int h) {
            this->height = h;
        }

        void setWidth(int w) {
            this->width = w;
        }

        long calculateArea() override {
            return this->height * this->width;
        }
};

class Square : public Shape {
    private:
        int side;
    public:
        Square() {
            
        }

        Square(int s) {
            this->side = s;
        }

        void setSide(int s) {
            this->side = s;
        }

        long calculateArea() override {
            return this->side * this->side;
        }
};

int main() {
    Rectangle *r = new Rectangle(5,6);
    Square *s = new Square(5);

    Shape *t = s; // Subtitute the shape object with square object
    cout << t->calculateArea() << endl;

    t = r; // Subtitute the shape object with rectangle object
    cout << t->calculateArea() << endl;

    return 0;
}