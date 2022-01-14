#include <vector>
#include <queue>

using namespace std;

int calculateDistance(int, int, vector<vector<int>>&, bool*);

vector<vector<int>> constructGraph(int, vector<vector<int>>&);

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
	// first, construct the graph
	// graph[origin] = [dest1, dest2, dest3];
	// graph[dest1] = [dest4, ...];

	vector<vector<int>> graph = constructGraph(n, edges);

	vector<int> result;
	for (int i = 1; i <= n; i++) {
		if (i == s) {
			continue;
		}

		// initialize visited flags
		bool *visited = new bool[n + 1];
		std::fill_n(visited, n, false);

		// calculate distance
		int distance = calculateDistance(s, i, graph, visited);

		// send result to vector
		result.push_back(distance);
	}

	return result;
}

int calculateDistance(int start, int end, vector<vector<int>> &graph, bool* visited) {
	queue<pair<int, int>> q;

	// - set visited to true
	q.push(make_pair(start, 0));
	visited[start] = true;

	while (!s.empty()) {
		pair<int, int> p = q.front();
		int node = q.first;
		int level = q.second;

		if (end == node) {
			return level * 6;
		}

		// pop element
		q.pop();

		for (int i = 0; i < graph[node].size(); i++) {
			int n = graph[node][i];

			if (!visited[n]) {
				visited[n] = true;
				q.push(make_pair(n, level + 1));
			}
		}
	}


	return -1;
}

vector<vector<int>> constructGraph(int n, vector<vector<int>> &edges) {
	vector<vector<int>> graph(n + 1);

	for (auto edge : edges) {
		int origin = edge.at(0);
		int dest = edge.at(1);

		graph[origin].push_back(dest);
		graph[dest].push_back(origin);
	}

	return graph;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
