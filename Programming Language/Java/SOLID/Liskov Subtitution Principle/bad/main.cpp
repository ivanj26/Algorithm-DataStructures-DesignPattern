#include <iostream>
using namespace std;

// Liskov-Subtitution Principle
// An instantiation / object from superclass should be replaceable by objects from its subclass
// without breaking the logic/validity of the application

// Bad way (Violates the LS principle)
class Rectangle {
    private:
        int width;
        int height;
    public:
        Rectangle() {

        }

        Rectangle(int _width, int _height) {
            this->width = _width;
            this->height = _height;
        }

        void setWidth(int _w) {
            this->width = _w;
        }

        void setHeight(int _h) {
            this->height = _h;
        }

        virtual int calculateArea() const {
            return width * height;
        }
};

class Square : public Rectangle {
    private:
        int side;
    public:
        Square() {

        }

        Square(int _w) {
            this->side = _w;
        }

        void setSide(int _w) {
            this->side = _w;
        }

        int calculateArea() const override {
            return this->side * this->side;
        }
};

int main() {
    Rectangle *r = new Rectangle();
    r->setHeight(10);
    r->setWidth(150);

    cout << "Rectangle area: " << r->calculateArea() << endl;
    
    // Subtitute the rectangle with square
    // Square is trying to immitate his parent
    Square *s = new Square(15);

    r = s;
    cout << "Rectangle area: " << r->calculateArea() << endl;

    delete r;

    return 0;
}