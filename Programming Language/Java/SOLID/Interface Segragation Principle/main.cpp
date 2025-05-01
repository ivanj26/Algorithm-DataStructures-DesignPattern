// Bad way in ISP is when you have a bloated interface

// Make it inconvinient when you have a class and want to inherit from this bloated interface
// You might not need implement all the method in the bloated interface
class BloatedInterface {
    public:
        virtual void methodA() = 0;
        virtual void methodB() = 0;
        virtual void methodC() = 0;
        // ...
        virtual void methodZ() = 0;
};

// Good way in ISP, separate into smaller interface.
// By chunking into the smaller interfaces, you can choose the interface which match with your needs
class SmallerInterfaceA {
    public:
        virtual void methodA() = 0;
        virtual void methodB() = 0;
        virtual void methodC() = 0;
};

class SmallerInterfaceB {
    public:
        virtual void methodD() = 0;
        virtual void methodE() = 0;
        virtual void methodF() = 0;
};

// so on...
class A: public SmallerInterfaceA {
    public:
        void methodA() override {

        }
        void methodB() override {

        }
        void methodC() override {

        }
};

int main() {
    return 0;
}