#include "singleton.cpp"
#include <iostream>

int main(int argc, const char** argv) {
    std::cout << Singleton::getInstance()->getValue() << std::endl;
    return 0;
}