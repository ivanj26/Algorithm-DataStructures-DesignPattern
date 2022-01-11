#include <iostream>
#include <vector>

using namespace std;

bool visit(vector<vector<int>> &connections, bool* visited, int index = 0) {
	if (visited[index]) {
		return true;
	}

	visited[index] = true;

	for (auto nextIndex : connections[index]) {
		if (visit(connections, visited, nextIndex)) {
			return true;
		}
	}

	visited[index] = false;

	return false;
}

/**
 * @brief Check if graph contains cycle
 * 
 * @param connections connections between node
 * @return true|false return true if deadlock
 */
bool hasDeadlock(vector<vector<int>> connections)
{
	bool n = connections.size();
	bool *visited = new bool[n];

	std::fill_n(visited, n, false);

	for (int i = 0; i < connections.size(); i++) {
		if (visit(connections, visited, i)) {
			return true;
		}
	}

	return false;
}