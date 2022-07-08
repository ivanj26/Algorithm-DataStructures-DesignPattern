#include <string>
#include "person.hpp"

#ifndef PERSON_BUILDER_HPP
#define PERSON_BUILDER_HPP

class PersonBuilder
{
    Person p;

    public:
        PersonBuilder(): p() {};
        PersonBuilder& setName(std::string name);
        PersonBuilder& setAddress(std::string address);
        Person build();
};

#endif