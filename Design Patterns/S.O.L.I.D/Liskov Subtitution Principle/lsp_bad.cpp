// Bad example
// Reason: the sub class is not ideal replacement for their base class. It will breaking the application logic.

#include <iostream>
using namespace std;

class Rectangle {
    protected:
        int height;
        int width;
    public:
        Rectangle() {

        }

        Rectangle(int h, int w) {
            this->height = h;
            this->width = w;
        }

        virtual void setHeight(int h) {
            this->height = h;
        }

        virtual void setWidth(int w) {
            this->width = w;
        }

        virtual long calculateArea() {
            return this->height * this->width;
        }
};

class Square : public Rectangle {
    public:
        Square() {
            
        }

        Square(int s) {
            this->width = s;
        }

        void setHeight(int v) override {
            this->width = v;
        }

        void setWidth(int v) override {
            this->width = v;
        }

        long calculateArea() override {
            return this->width * this->width;
        }
};

int main() {
    Rectangle *r = new Rectangle(2,5);
    cout << r->calculateArea() << endl; // 10

    Square *s = new Square();
    r = s;

    r->setWidth(6);
    cout << r->calculateArea() << endl; // expect: 12, but it returns 36

    delete r;

    return 0;
}