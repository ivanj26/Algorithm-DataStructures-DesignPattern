#include <iostream>
#include "person_builder.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    PersonBuilder builder = Person::Builder();
    Person p = builder
        .setName("Ivan J")
        .setAddress("Address 1")
        .build();
    
    cout << p.getName() << endl;
    cout << p.getAddress() << endl;
    return 0;
}
