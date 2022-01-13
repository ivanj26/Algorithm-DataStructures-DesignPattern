#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool numericStringCompare(const string& s1, const string& s2) {
	if (s1.length() == s2.length()) {
		int i = 0;
		for (; i < s1.length() - 1; i++) {
			int s1Int = s1[i] - '0';
			int s2Int = s2[i] - '0';

			if (s1Int < s2Int) {
				return true;
			} else if (s1Int > s2Int) {
				return false;
			}
		}

		return s1[i] < s2[i];
	}

	return s1.length() < s2.length();
}

vector<string> bigSorting(vector<string> unsorted) {
	std::sort(unsorted.begin(), unsorted.end(), numericStringCompare);

	return unsorted;
}
