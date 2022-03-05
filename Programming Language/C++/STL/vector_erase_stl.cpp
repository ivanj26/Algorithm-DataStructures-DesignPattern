#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// Problem set: https://www.hackerrank.com/challenges/vector-erase/problem?isFullScreen=true

int main() {
	int size;
	vector<int> v;
	
	// Read input
	cin >> size;
	for (int i = 0; i < size; i++) {
		int num;
		cin >> num;
		
		v.push_back(num);
	}
	
	int x;
	cin >> x;
	int a, b;
	cin >> a >> b;
	
	// v.erase(v.begin() + 2) -> Erase the third element
	// v.erase(v.begin() + 2, v.begin() + 4) -> Erase the third element until fifth element
	v.erase(v.begin() + (x - 1));
	v.erase(v.begin() + (a - 1), v.begin() + (b - 1));
	
	// Print output
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	return 0;
}
