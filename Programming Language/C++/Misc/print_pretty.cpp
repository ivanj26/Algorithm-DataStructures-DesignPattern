#include <iostream>
#include <iomanip>
using namespace std;

// Problem set: https://www.hackerrank.com/challenges/prettyprint/problem?isFullScreen=true

int main()
{
	int T;
	cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while (T--)
	{
		double A;
		cin >> A;
		double B;
		cin >> B;
		double C;
		cin >> C;


		printf("%#lx\n", (long int)A);
		printf(
			"%.*s%+.2f\n",
			(15 - to_string((int)B).length() - 4),
			"_______________",
			B);
		printf("%.9E\n", C);
	}
	return 0;
}