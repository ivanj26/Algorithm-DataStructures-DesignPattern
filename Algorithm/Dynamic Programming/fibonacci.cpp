#include <vector>
#include <iostream>
using namespace std;

/**
 * Fibonacci using recursive
 * Time complexity  : T(n-1) + T(n-2) -> Exponential 
 * Space            : O(n)
 **/
int fib1(int n)
{
	if (n <= 1)
		return n;
	else
		return fib1(n - 1) + fib1(n - 2);
}

/**
 * Fibonacci using dynamic programming
 * Time complexity : O(n)
 * Space           : O(n)
**/
int fib2(int n)
{
	int f[n + 1];

	f[0] = 0;
	f[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
	}

	return f[n];
}

// fib array must be initialize with n size
// n must be large enough
// Problem: https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem
int fibRecursive(int *fib, int n, int i = 1)
{
    if (n == 0 || n == 1) {
        return fib[n];
    }

    if (n != i) {
        i++;
        fib[i] = fib[i - 2] + fib[i - 1];
        return fibRecursive(fib, n, i);
    }

    return fib[i];
}

/**
 * Fibonnaci using dynamic programming with space optimized
 * Time complexity  : O(n)
 * Space            : O(1)
 **/
int fib3(int n)
{
	int x = 0, y = 1, z;
	if (n == 0)
	{
		return x;
	}

    if (n == 1)
    {
        return y;
    }

	for (int i = 2; i <= n; i++)
	{
		z = x + y; //Replace by adding f[i-2] + f[i-1]
		x = y;     //Replace f[i-2] = f[i-1]
		y = z;     //Replace f[i-1] = f[i]
	}

	return z;
}

/**
 * Based on fibonacci algorithm with a little configuration inside
 **/

int climbingStairs(int n)
{
	int f[n + 1];
	f[0] = 0;
	f[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		f[i] = f[i - 1] + f[i - 2];
		if (i == 2)
			f[i]++;
	}

	return f[n];
}

int main(int argc, const char **argv)
{
	int n = 9;
	cout << "Fib of 9: " << fib1(n) << endl;
	cout << "Fib of 9: " << fib2(n) << endl;
	cout << "Fib of 9: " << fib3(n) << endl;

	return 0;
}