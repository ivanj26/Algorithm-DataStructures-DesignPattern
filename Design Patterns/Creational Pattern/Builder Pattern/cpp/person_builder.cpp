#include "person_builder.hpp"

PersonBuilder::PersonBuilder(): p() {
    //
}

PersonBuilder& PersonBuilder::setName(std::string name) {
    p.name = name;
    return *this;
}

PersonBuilder& PersonBuilder::setAddress(std::string address) {
    p.address = address;
    return *this;
}

Person PersonBuilder::build() {
    return p;
}