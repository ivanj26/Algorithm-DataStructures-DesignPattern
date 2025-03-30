#include <iostream>
using namespace std;

// Liskov-Subtitution Principle
// An instantiation / object from superclass should be replaceable by objects from its subclass
// without breaking the logic/validity of the application

// Good way to make superclass object replaceable by subclasses
class Shape {
    public:
        virtual int calculateArea() = 0;
        virtual ~Shape() {}
};

class Rectangle: public Shape {
    private:
        int height, width;
    public:
        Rectangle() {

        }

        void setWidth(int _w) {
            this->width = _w;
        }

        void setHeight(int _h) {
            this->height = _h;
        }

        int calculateArea() override {
            return width * height;
        }
};

class Square: public Shape {
    private:
        int side;
    public:
        Square() {

        }

        void setSide(int _w) {
            this->side = _w;
        }

        int calculateArea() override {
            return side * side;
        }
};

int main() {
    Rectangle *r = new Rectangle();
    r->setHeight(10);
    r->setWidth(15);

    Square *s = new Square();
    s->setSide(15);

    Shape *st = s;
    cout << "Area of shape (square): " << st->calculateArea() << endl;

    st = r;
    cout << "Area of shape (rectangle): " << st->calculateArea() << endl;

    delete s;
    delete r;

    return 0;
}