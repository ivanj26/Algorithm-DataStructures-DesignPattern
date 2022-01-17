#include <vector>
#include <unordered_set>

using namespace std;

int possibleSum(vector<int> coins, vector<int> quantities) {
	unordered_set<int> s
	s.insert(0);

	for (int i = 0; i < coins.size(); i++) {
		auto temp = s;
		int freq = quantities.at(i);

		for (int f = 1; f <= freq; ++f) {
			for (int elmt : temp) {
				s.insert(elmt + (f * coins[i]));
			}
		}
	}

	return s.size() - 1;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
