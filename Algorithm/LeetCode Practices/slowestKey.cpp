#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

char slowestKey(vector<int> &releaseTimes, string keysPressed) {
	assert(releaseTimes.size() == keysPressed.size());
	assert(releaseTimes.size() > 0 && keysPressed.size() > 0);

	int max = releaseTimes.at(0);
	char slowestKey = keysPressed.at(0);

	for (int i = 1; i < releaseTimes.size(); i++) {
		int diff = releaseTimes[i] - releaseTimes[i-1];
		char c = keysPressed[i];

		if (max < diff || (max == diff && c > slowestKey)) {
			max = diff;
			slowestKey = c;
		}
	}

	return slowestKey;
}

int main(int argc, char const *argv[])
{
	vector<int> r = {9,29,49,50};
	string k = "cbcd";

	cout << slowestKey(r, k) << endl;
	return 0;
}
