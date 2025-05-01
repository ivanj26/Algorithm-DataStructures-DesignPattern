#include <vector>
#include <queue>

using namespace std;

// n = number of nodes
// m = number of edges
// edges = relationship between nodes
// s = starting node
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<vector<int>> newEdges(n+1, vector<int>());
    for (vector<int> edge: edges) {
        int from = edge[0];
        int to = edge[1];

        newEdges[from].push_back(to);
        newEdges[to].push_back(from);
    }

    vector<int> distances(n, -1); // Fill with default value -1
    distances[s-1] = 0;
    
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int currNode = q.front();
        vector<int> newEdge = newEdges[currNode];

        for (int targetNode : newEdge) {
            if (distances[targetNode-1] == -1) {
                distances[targetNode-1] = distances[currNode-1] + 6;
                q.push(targetNode);
            }
        }

        q.pop();
    }

    vector<int> out;
    for (int i = 0; i < n; i++) {
        if (i != s-1) {
            out.push_back(distances[i]);
        }
    }

    return out;
}