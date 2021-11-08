// Source: https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/problem
#include <vector>
#include <iostream>
#include <set>
#include <queue>

using namespace std;

class Graph {
    private:
        vector<int> *vec;
        vector<int> res;
        int nodes;
    public:
        Graph(int n) {
            this->nodes = n;

            vec = new vector<int>[n];
            res = vector<int>(n, -1);
        }

        void addEdge(int u, int v) {
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        void traverse(int start, int target) {
            queue< pair<int, int> > q;
            set<int> s;

            q.push(make_pair(start, 0));
            s.insert(start);

            while (!q.empty()) {
                pair<int, int> front = q.front();
                q.pop();

                int node = front.first;
                int count = front.second;

                vector<int> v = vec[node];
                if (v.empty()) {
                    if (count > 0) {
                        res[target] = count;
                        return;
                    }
                }

                count += 6;
                for (auto val : v) {
                    if (val == target) {
                        res[target] = count;
                        return;
                    }

                    const bool found = s.find(val) != s.end();
                    if (!found) {
                        q.push(make_pair(val, count));
                        s.insert(val);
                    }
                }
            }
        }

        vector<int> shortestReach(int start) {
            for (int i = 0; i < this->nodes; i++) {
                if (i != start) {
                    traverse(start, i);
                }
            }
        }
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.addEdge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortestReach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}