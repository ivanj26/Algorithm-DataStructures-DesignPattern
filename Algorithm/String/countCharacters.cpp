#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int countCharacters(vector<string> &words, string chars) {
	unordered_map<char, int> map;

	for (char c : chars) {
		map[c]++;
	}

	int sum = 0;
	for (string word : words) {
		unordered_map<char, int> map2 = map;

		for (int i = 0; i < word.length(); i++) {
			char c = word[i];
			if (map2[c]) {
				if (i == word.length() - 1) {
					sum += word.length();
					break;
				}

				map2[c]--;
			} else {
				break;
			}
		}
	}

	return sum;
}