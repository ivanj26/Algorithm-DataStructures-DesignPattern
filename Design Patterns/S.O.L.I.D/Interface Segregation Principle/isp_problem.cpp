// (L)iskov Subtitution Principle
//
// This principle suggests to keep the interface(s) to be smaller parts and specific rather the monolithic one.
#include <stdexcept>
#include <iostream>
using namespace std;

class IPrinter {
    public:
        virtual ~IPrinter() = default;
        virtual void print() = 0;
        virtual void scan() = 0;
};

// Let say, we have 2 types of printers, a basic printer and multi-function printer.
// The basic printer cannot do Scan(), while the multi-function printer can do both.

class BasicPrinter: public IPrinter {
    public:
        void print() override {
            std::cout << "Printing..." << std::endl;
        }

        void scan() override {
            throw std::runtime_error("Unimplemented, not supported");
        }
};


class MultiFuncPrinter: public IPrinter {
    public:
        void print() override {
            std::cout << "Printing..." << std::endl;
        }

        void scan() override {
            std::cout << "Scanning..." << std::endl;
        }
};

// The above classes violate the IS Principle because you can teardown the interface to smaller parts
// For example, you can separate the IPrinter to two interfaces
//  1. IScanner to scan the document.
//  2. IPrinter to print the document.
//
// By splitting the interface, the BasicPrinter and MultiFuncPrinter to implement the interface(s) that they actually use to. 
//
// Solution: isp_solution.cpp

int main(int argc, char const *argv[])
{
    IPrinter *basicPrinter = new BasicPrinter();
    basicPrinter->print();
    // basicPrinter->scan(); // Will throw an error
    
    IPrinter *multiPrinter = new MultiFuncPrinter();
    multiPrinter->print();
    multiPrinter->scan();

    delete basicPrinter;
    delete multiPrinter;

    return 0;
}
