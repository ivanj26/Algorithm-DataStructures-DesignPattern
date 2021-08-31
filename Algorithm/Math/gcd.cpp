#include <iostream>

// using recursive
int gcdRecv(int a, int b)
{
	if (a == 0)
	{
		return b;
	}
	if (b == 0)
	{
		return a;
	}

	if (a == b)
	{
		return a;
	}

	if (a > b)
	{
		return gcdRecv(a - b, b);
	}
	else
	{
		return gcdRecv(a, b - a);
	}
}

// using euclidean algorithm
int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}

	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}

int main(int argc, char const *argv[])
{
	std::cout << gcd(15, 20) << std::endl;
	std::cout << lcm(15, 20) << std::endl;
	return 0;
}
