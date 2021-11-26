#include <iostream>
#include <string>

using namespace std;

string reverse(string str) {
	if (str.length() < 2) {
		return str;
	}

	return reverse(str.substr(1)) + str.at(0);
}

int main(int argc, char const *argv[])
{
	cout << reverse("abcde") << endl;
	return 0;
}
