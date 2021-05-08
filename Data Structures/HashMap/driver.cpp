#include "hashmap.cpp"
#include <iostream>

struct MyKeyHash {
    size_t size = 2;
    unsigned long operator() (int key) const {
        return static_cast<unsigned long>(key) % size;
    }
};

int main(int argc, const char** argv) {
    HashMap<int, std::string, MyKeyHash> map;
    map.put(1, "Test");
    map.put(3, "Hello world!");
    map.put(4, "Hello dlrow!");
    map.put(5, "Hello dlrow!");
    map.put(7, "Hello dlrow!");
    map.put(8, "Hello dlrow!");

    map.remove(3);

    std::cout << "Result: " << endl;
    std::cout << map[1] << std::endl;

    for (int key : map.keys()) {
        std::cout << key << " " << map.get(key) << std::endl;
    }

    return 0;
}

// int main(int argc, const char** argv) {
//     HashMap<int, std::string> map;
//     map.put(1, "Hello");
//     map.put(2, "World");

//     map.remove(1);
//     try {
//         std::string val2 = map.get(2);
//         std::cout << val2 << std::endl;

//         std::string val = map.get(3);
//     } catch(std::exception& e) {
//         std::cout << e.what() << std::endl;
//     }
    
//     return 0;
// }
