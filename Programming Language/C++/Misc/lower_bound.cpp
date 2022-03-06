#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n;
	
	cin >> n;
	int i = 0;
	vector<int> v;
	while (i < n) {
		int num;
		cin>>num;
		
		v.push_back(num);
		i++;
	}
	
	int q;
	cin>>q;
	
	for (int i = 0; i < q; i++) {
		int num;
		cin >> num;
		
		vector<int>::iterator low = std::lower_bound(v.begin(), v.end(), num);
		if (*low == num) {
			cout << "Yes " << (low - v.begin() + 1) << endl;
		} else {
			cout << "No " << (low - v.begin() + 1) << endl;
		}
	}
	
	return 0;
}
