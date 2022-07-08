#include <iostream>
#include "computerfactory.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Computer *c = ComputerFactory::create("Laptop");
    if (c != nullptr)
    {
        cout << "Computer Type: " << c->getName() << endl;
    }

    delete c;
    return 0;
}
