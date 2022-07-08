#include <stdexcept>
#include <string>
#include "computer.hpp"
#include "laptop.cpp"
#include "desktop.cpp"

constexpr unsigned int hash(const char *s, int off = 0) {                        
    return !s[off] ? 5381 : (hash(s, off+1)*33) ^ s[off];                           
}

class ComputerFactory
{
    public:
        static Computer *create(std::string type) throw()
        {
            switch (hash(type.c_str()))
            {
                case hash("Laptop"):
                {
                    return new Laptop();
                }
                case hash("Desktop"):
                {
                    return new Desktop();
                }
                default:
                {
                    throw std::runtime_error("Cannot identify the type");
                }
            }

            return nullptr;
        }
};