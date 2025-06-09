#include <iostream>

using namespace std;

int main() {
    int a = 5;
    int b = 7;

    cout << "Before Swap, Current A: " << a << endl;
    cout << "Before Swap, Current A: " << b << endl;

    a = b - a;
    b = b - a;

    a = a + b;

    cout << "Current A: " << a << endl;
    cout << "Current B: " << b << endl;
    
    return 0;
}