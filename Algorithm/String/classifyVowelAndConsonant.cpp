#include <string>
#include <iostream>

using namespace std;

bool isVowel(char c) {
	return c == 'i' || c == 'a' || 'u' == c || 'o' == c || 'e' == c;
}

/**
 * @brief Classify if string is good or bad or mixed.
 * 
 * Bad: If there is a substring has 3 consecutive vowels or 5 consecutive consonants
 * Good: if opposite with 'Bad' rule.
 * 
 * Mixed: The string can also contain the character ?, which can be replaced by either a vowel or a consonant.
 * This means that the string "?aa" can be bad if ? is a vowel or good if it is a consonant.
 * This kind of string is categorized as mixed.
 * 
 * @return classified (good|bad|mixed).
 * 
 */
string classifyString(string s) {
	// check if string has wildcard character or not (wildcard: ?)
	size_t pos = s.find('?');

	if (pos == string::npos) {
		// if wildcard not found
		// we can count the characters is it bad or good
		int v = 0;
		int c = 0;

		for (auto c : s) {
			if (isVowel(c)) {
				++v;
				c = 0;
			} else {
				++c;
				v = 0;
			}

			if (v == 3 || c == 5) {
				return "bad";
			}
		}

		return "good";
	}

	// replace wildcard with vowel and consonant character
	// we need to eliminate wildcard character by replacing it

	// replace to any vowel character
	s[pos] = 'a';

	// do recursive
	string r1 = classifyString(s);

	// replace to any consonant character
	s[pos] = 'v';

	// do recursive
	string r2 = classifyString(s);

	if ((r1 == "good" && r2 == "good") || (r1 == "bad" && r2 == "bad")) {
		return r1;
	}

	return "mixed";
}

int main(int argc, char const *argv[])
{
	cout << classifyString("a?ui") << endl;
	return 0;
}
