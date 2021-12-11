#include <vector>
#include <iostream>

using namespace std;

vector<short> plusOne(vector<short> &digits) {
	uint lastIdx = digits.size() - 1;
	short val = digits[lastIdx];
	vector<short> copy = digits;

	if (val + 1 > 9)
	{
		short carry = 1;

		for (uint i = lastIdx; i >= 0; i--) {
			if (carry > 0) {
				short sum = copy[i] + 1;
				if (sum > 9) {
					carry = 1;
					sum = 0;
				} else {
					carry = 0;
				}

				copy[i] = sum;
			} else {
				break;
			}
		}

		if (carry > 0) {
			copy.insert(copy.begin(), 1);
		}
	} else
	{
		copy[lastIdx]++;
	}

	return copy;
}

int main(int argc, char const *argv[])
{
	vector<short> before = {9, 8, 9, 9};
	vector<short> after = plusOne(before);

	for (uint i = 0; i < after.size(); i++) {
		cout << after[i];
	}
	cout << endl;

	return 0;
}
