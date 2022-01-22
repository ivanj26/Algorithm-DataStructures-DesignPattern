#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int mininumGroup(vector<int> &predators) {
	unordered_map<int, int> visited;
	int max = INT_MIN;
	int baseLevel = 1;

	for (int i = 0; i < predators.size(); i++) {
		int j = i;
		int counter = baseLevel;

		if (visited.find(predators[j]) != visited.end()) {
			int levelPredatorJ = visited[predators[j]];
			levelPredatorJ++;

			visited.insert(make_pair(i, levelPredatorJ));
		} else {

			while (predators[j] > -1) {
				counter++;
				j = predators[j];
			}

			visited.insert(make_pair(i, counter));
			if (max < counter) {
				max = counter;
			}
		}
	}


	return max;
}

int main(int argc, char const *argv[])
{
	vector<int> v = {-1, 8, 6, 0, 7, 3, 8, 9, -1, 6, 1};

	cout << mininumGroup(v) << endl;

	return 0;
}
