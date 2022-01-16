#include <iostream>
#include <math.h>

using namespace std;

/**
 * @brief Given terms t[i] and t[i+1] where i element of (1, infinity)
 * 		  term t[i + 2] is computed as:
 * 				t[i+2] = t[i] + (t[i-1] ^ 2)
 * 
 * @param t1 
 * @param t2 
 * @param n 
 * @return long long 
 */
long long fibonacciModified(int t1, int t2, int n) {
	int m = 3;

	long long tnmin2 = t1;
	long long tnmin1 = t2;
	long long tn = 1;

	while (m <= n) {
		tn = tnmin2 + pow(tnmin1, 2);
		tnmin2 = tnmin1;
		tnmin1 = tn;

		m++;
	}

	return tn;
}

int main(int argc, char const *argv[])
{
	cout << fibonacciModified(0, 2, 5) << endl;
	return 0;
}
