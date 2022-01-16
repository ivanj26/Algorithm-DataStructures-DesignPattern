#include <string>
#include <queue>
#include <iostream>

using namespace std;

string hackerrankInString(string s) {
	queue<char> q;
	q.push('h');
	q.push('a');
	q.push('c');
	q.push('k');
	q.push('e');
	q.push('r');
	q.push('r');
	q.push('a');
	q.push('n');
	q.push('k');

	for (auto c : s) {
		int front = q.front();

		if (front == c) {
			if (!q.empty()) {
				q.pop();
			} else {
				return "YES";
			}
		}
	}

	return !q.empty() ? "NO" : "YES";
}

int main(int argc, char const *argv[])
{
	cout << hackerrankInString("hereiamstackerrank") << endl;
	return 0;
}
