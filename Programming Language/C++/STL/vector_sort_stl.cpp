#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Problem set: https://www.hackerrank.com/challenges/vector-sort/problem?isFullScreen=true

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	vector<int> v;
	int i = 0;
	while (i < n) {
		int num;
		cin >> num;

		v.push_back(num);
		i++;
	}

	// Sort by ascending
	// we need to import <algorithm> to using std::sort
	std::sort(v.begin(), v.end());
	i = 0;

	while (i < n) {
		cout << v[i] << " ";
		i++;
	}
	cout << endl;

	return 0;
}
