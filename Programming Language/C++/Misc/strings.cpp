#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Complete the program
	string s1, s2;

	getline(cin, s1);
	getline(cin, s2);

	// print first line
	cout << s1.length() << " " << s2.length() << endl;

	// print second line
	cout << (s1 + s2) << endl;

	// print last line
	char c = s2[0];
	s2[0] = s1[0];
	s1[0] = c;

	cout << s1 << " " << s2 << endl;

	return 0;
}
