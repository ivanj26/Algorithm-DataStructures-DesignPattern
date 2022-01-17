#include <math.h>
#include <iostream>
using namespace std;

bool isPrime(unsigned int num)
{
	if (num <= 1) {
		return false;
	}

	int squareRoot = sqrt(num);

	for (int i = 2; i <= squareRoot; i++) {
		if (num % i == 0) {
			return false;
		}
	}

	return true;
}

int main(int argc, char const *argv[])
{
	std::cout << "is 18 is prime number? " << (isPrime(18) ? "Yes" : "No") << std::endl;
	return 0;
}
