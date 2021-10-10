#include <queue>
#include <iostream>

using namespace std;

long reverse(long x) {
    queue<int> q;

    bool isMinus = x < 0;
    if (isMinus) {
        x *= -1;
    }

    while (x > 0) {
        int mod = x % 10;
        x /= 10;

        q.push(mod);
    }

    unsigned int sum = 0;
    while (!q.empty()) {
        int val = q.front();

        int size = q.size() - 1;
        unsigned int base = 1;

        while (size > 0) {
            size--;
            base *= 10;
        }

        sum = sum + (base * val);
        q.pop();
    }

    return isMinus ? -(sum) : sum;
}

int main(int argc, char const *argv[])
{
    cout << reverse(100055) << endl;
    return 0;
}
