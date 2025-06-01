// (I)nterface Segregation Principle
//
// This principle suggests to keep the interface(s) to be smaller parts and specific rather the monolithic one.
#include <stdexcept>
#include <iostream>
using namespace std;

class IPrinter {
    public:
        virtual ~IPrinter() = default;
        virtual void print() = 0;
};

class IScanner {
    public:
        virtual ~IScanner() = default;
        virtual void scan() = 0;
};

// Let say, we have 2 types of printers, a basic printer and multi-function printer.
// The basic printer cannot do Scan(), while the multi-function printer can do both.

class BasicPrinter: public IPrinter {
    public:
        void print() override {
            std::cout << "Printing..." << std::endl;
        }
};


class MultiFuncPrinter: public IScanner, public IPrinter {
    public:
        void print() override {
            std::cout << "Printing..." << std::endl;
        }

        void scan() override {
            std::cout << "Scanning..." << std::endl;
        }
};

int main(int argc, char const *argv[])
{
    IPrinter *basicPrinter = new BasicPrinter();
    basicPrinter->print();
    
    MultiFuncPrinter *multiPrinter = new MultiFuncPrinter();
    multiPrinter->print();
    multiPrinter->scan();

    delete basicPrinter;
    delete multiPrinter;

    return 0;
}
