#include <iostream>
#include <string>

using namespace std;

string reverse(string str) {
	if (str.length() == 1) {
		return str;
	}

	int size = str.size();
	int lastIdx = size - 1; 
	return str.at(lastIdx) + reverse(str.substr(0, size - 1));
}

int main(int argc, char const *argv[])
{
	cout << reverse("abcde") << endl;
	return 0;
}
