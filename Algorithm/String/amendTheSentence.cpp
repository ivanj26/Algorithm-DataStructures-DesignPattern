#include <string>
#include <iostream>

using namespace std;

void insertToResult(string &result, string &temp)
{
	result += (result.length() > 0) ? (' ' + temp) : temp;
	temp = "";
}

/**
 * @brief Given a raw string from caller then amend the given string.
 * 
 * You have been given a string s, which is supposed to be a sentence.
 * However, someone forgot to put spaces between the different words, and for some reason they capitalized the first letter of every word.
 * 
 * Return the sentence after making the following amendments:
 * 1. Put a single space between the words.
 * 2. Convert the uppercase letters to lowercase.
 * 
 * @param s 
 * @return string 
 */
string solution(string s)
{
	string result;
	int len = s.length();

	for (int i = 0; i < len; i++) {
		char c = s[i];

		if (isupper(c)) {
			string temp;

			temp += tolower(c);

			if (i < len - 1)
			{
				int j = i + 1;
				for (; j < len; j++) {
					char c = s[i];

					if (isupper(c)) {
						insertToResult(result, temp);
						break;
					}

					temp += c;
				}

				if (j == len) {
					insertToResult(result, temp);
				}

				i = j - 1;
			} else {
				insertToResult(result, temp);
			}
		} else {
			result += c;
		}
	}

	return result;
}

int main(int argc, char const *argv[])
{
	string res = solution("A Codesignal amend StrinG");
	cout << res << endl;
	return 0;
}
