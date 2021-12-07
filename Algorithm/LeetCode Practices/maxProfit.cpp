#include <vector>
#include <iostream>

using namespace std;


int maxProfit(vector<int> &prices) {
	int min = INT_MAX;
	int max = INT_MIN;

	for (auto price: prices) {
		min = std::min(min, price);
		max = std::max(max, price - min);
	}

	return max;
}

int main(int argc, char const *argv[])
{
	vector<int> v = { 2, 5, 1, 0, 10 };

	cout << "Max profit Buy/Sell Stock: " << maxProfit(v) << endl;
	return 0;
}
