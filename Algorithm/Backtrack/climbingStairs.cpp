#include <vector>
#include <iostream>

/**
 * @brief There are n steps in the staircase, and you can jump up k or fewer steps at a time.
 * There are x potential sequences in which you jump up the stairs either k or <k at a time.
 * 
 */

using namespace std;

void backtrack(int n, int k, vector<int> temp, vector<vector<int>> &res)
{
	if (n == 0) {
		res.push_back(temp);
	}

	for (int i = 1; i <= min(n, k); i++) {
		temp.push_back(i);
		backtrack(n - i, k, temp, res);
		temp.pop_back();
	}
}

int main(int argc, char const *argv[])
{
	vector<vector<int>> res;
	int n = 4;
	int k = 2;

	backtrack(n, k, vector<int> {}, res);

	for (auto vec : res) {
		for (auto num : vec) {
			cout << num << " ";
		}
		cout << endl;
	}

	return 0;
}
