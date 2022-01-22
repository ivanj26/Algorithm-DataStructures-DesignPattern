#include <iostream>

using namespace std;

int countNumberWithUniqueDigits(int digit) {
	// digit: 0 => 0
	// digit: 1, [0..9] => 10
	// digit: 2, [10..99]
	//           except 11, 22, 33, 44, 55, 66 , 77, 88, 99 = 100 - 9 = 91
	// digit: 3, 91 + (9 * 9 * 8) = 739
	// digit: 4, 739 + (9 * 9 * 8 * 7) = 5275

	int base = 9;
	int ans = 10;

	if (digit == 1) {
		return 0;
	}

	for (int i = 2; i <= digit && i <= 10; i++) {
		base *= (9 - i + 2);
		ans += base;
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	cout << countNumberWithUniqueDigits(2) << endl;
	return 0;
}
