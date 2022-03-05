#include <vector>
#include <iostream>

using namespace std;

int wayToSum(int n, int k) {
	// n = 8
	// k = 2

	// [1,1,1,1,1,1,1,1]
	// [1,1,1,1,1,1,2]
	// [1,1,1,1,2,2]
	// [1,1,2,2,2]
	// [2,2,2,2]

	vector<int> v(n + 1);
	fill_n(v.begin(), n + 1, 0);

	v[0] = 1;

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if (j >= i) {
				// v[1] = v[1] + v[0] = 1
				// v[2] = v[2] + v[1] = 1
				// ...
				// v[8] = v[8] + v[7] = 1

				// v[2] = v[2] + v[0] = 1 + 1 = 2
				// v[3] = v[3] + v[1] = 1 + 1 = 2
				// v[4] = v[4] + v[2] = 1 + 2 = 3
				// v[5] = v[5] + v[3] = 1 + 2 = 3
				// v[6] = v[6] + v[4] = 1 + 3 = 4
				// v[7] = v[7] + v[5] = 1 + 3 = 4
				// v[8] = v[8] + v[6] = 1 + 4 = 5
				v[j]  = v[j] + v[j - i];
			}
		}
	}

	return v[n];
}

int main(int argc, char const *argv[])
{
	cout << wayToSum(8, 2) << endl;
	return 0;
}
