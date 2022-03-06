#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

// Problem: https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem?isFullScreen=true

vector<int> parseInts(string str) {
	stringstream ss(str);
	
	vector<int> v;
	int num;
	char ch;
	
	while (ss >> num) {
		v.push_back(num);
		ss >> ch;
	}
	
	return v;
}

int main() {
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for(int i = 0; i < integers.size(); i++) {
		cout << integers[i] << "\n";
	}
	
	return 0;
}
