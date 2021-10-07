#include <vector>
#include <iostream>

using namespace std;

bool isPalindrome(int x)
{
	if (x < 0)
	{
		return false;
	}

	vector<int> v;
	while (x > 0)
	{
		int mod = x % 10;
		x /= 10;

		v.push_back(mod);
	}

	bool isPal = true;
	int i = 0;
	int halfSize = v.size() / 2;
	while (i < halfSize)
	{
		int j = v.size() - i - 1;
		isPal = v.at(i) == v.at(j);

		if (isPal == false)
		{
			break;
		}

		i++;
	}

	return isPal;
}

int main(int argc, char const *argv[])
{
	if (argc < 2) {
		cout << "insufficient arguments" << endl;
		return 0;
	}

	int x = atoi(argv[1]);

	cout << "is palindrome?\t:";
	cout << (isPalindrome(x) ? "true" : "false") << endl;
	return 0;
}
