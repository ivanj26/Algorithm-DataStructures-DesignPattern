#include <iostream>
#include "./set.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Set<int> s;
    s.add(1);
    s.add(10);
    s.add(9);
    s.add(5);
    s.add(1);
    s.remove(2);

    cout << "Key: 3\t";
    cout << (s.contains(3) ? "Exist" : "Not Exist") << endl;

    cout << "Key: 5\t";
    cout << (s.contains(5) ? "Exist" : "Not Exist") << endl;

    return 0;
}

