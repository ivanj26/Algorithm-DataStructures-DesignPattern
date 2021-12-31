#include <string>
#include <iostream>

using namespace std;

void search(string text, string keyword)
{
	int m = text.size();
	int n = keyword.size();

	for (int i = 0; i <=  m - n; i++) {
		int j;

		for (j = 0; j < n; j++) {
			if (text[i + j] != keyword[j]) {
				break;
			}
		}

		if (j == n) {
			cout << "Keyword matched at index : " << i << endl;
			break;
		} else {
			if (i >= m - n) {
				cout << "Keyword not found in text" << endl;
			}
		} 
	}
}

int main(int argc, char const *argv[])
{
	search("blablablablablblablablbalblaC+", "C++");
	return 0;
}
