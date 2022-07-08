#include <string>

#ifndef PERSON_HPP
#define PERSON_HPP

class PersonBuilder;

class Person
{
    private:
        std::string name;
        std::string address;
    public:
        friend class PersonBuilder;
        static PersonBuilder Builder();

        std::string getName() const;
        std::string getAddress() const;
};

#endif