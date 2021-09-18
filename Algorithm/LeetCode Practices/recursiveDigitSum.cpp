#include <string>
using namespace std;

int num(long long int val)
{
	if (val < 10)
	{
		return val;
	}
	else
	{
		long long int result = 0;

		while (val > 0)
		{
			int mod = val % 10;
			val /= 10;

			result += mod;
		}

		return num(result);
	}
}

int superDigit(string n, int k)
{
	long long int sum = 0;

	for (int i = 0; i < n.size(); i++)
	{
		sum += n[i] - '0';
	}

	return num(sum * k);
}