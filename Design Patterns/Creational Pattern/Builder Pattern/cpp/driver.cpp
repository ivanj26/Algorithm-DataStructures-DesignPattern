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

    Person p2 = builder
        .setName("Ivan Jo")
        .setAddress("Address 2")
        .build();
    
    cout << p.getName() << endl;
    cout << p.getAddress() << endl;

    cout << endl;
    cout << p2.getName() << endl;
    cout << p2.getAddress() << endl;
    return 0;
}
