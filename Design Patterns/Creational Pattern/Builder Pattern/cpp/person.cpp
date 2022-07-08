#include <string>
#include "person_builder.hpp"

PersonBuilder Person::Builder() {
    return PersonBuilder();
}

std::string Person::getName() const {
    return this->name;
}

std::string Person::getAddress() const {
    return this->address;
}