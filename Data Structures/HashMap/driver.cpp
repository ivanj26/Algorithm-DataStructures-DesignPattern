#include "hashmap.cpp"
#include <iostream>
#include <exception>

int main(int argc, const char** argv) {
    HashMap<int, std::string> map;
    map.put(1, "Hello");
    map.put(2, "World");

    map.remove(1);
    try {
        std::string val2 = map.get(2);
        std::cout << val2 << std::endl;

        std::string val = map.get(3);
    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
