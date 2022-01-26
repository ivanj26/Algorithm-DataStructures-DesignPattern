#include <iostream>
using namespace std;

unsigned int reverse(unsigned int n) {
	unsigned int rev = 0;

	while (n > 0) {
		// shift right rev
		rev <<= 1;

		if (n & 1 == 1) {
			rev ^= 1;
		}

		// shift left n
		n >>= 1;
	}

	return rev;
}

int main(int argc, char const *argv[])
{
	cout << reverse(11) << endl;
	return 0;
}
