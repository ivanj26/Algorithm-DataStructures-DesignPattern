#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
        bool canFinish(int nums, vector<vector<int>> &prerequisites) {
            vector<vector<int>> directedGraph(nums);
            vector<int> incomingArrow(nums, 0);

            // Construct the directed graph in 2d array & `incoming arrow` for each nodes in array
            for (vector<int> v : prerequisites) {
                int from = v[0];
                int to = v[1];

                directedGraph[from].push_back(to);
                incomingArrow[to]++;
            }

            // Add "root nodes" into our queue
            // Root node: A node is a root node if there is no incoming arrow/degree 
            queue<int> qroots;
            for (int i = 0; i < nums; i++) {
                if (incomingArrow[i] == 0) {
                    qroots.push(i);
                }
            }

            // Check for every root nodes
            int totalVisited = 0;
            while (!qroots.empty()) {
                int root = qroots.front();
                qroots.pop();

                totalVisited++;

                // Traverse our root node in our directed graph
                vector<int> adjacentNodes = directedGraph[root];
                for (int node : adjacentNodes) {
                    // Mark node as visited by reducing the incomingArrow[node] by 1
                    incomingArrow[node]--;

                    // If we cannot visit the node, do not push it to our queue
                    // Otherwise push it.
                    if (incomingArrow[node] == 0) {
                        qroots.push(node);
                    }
                }
            }

            // Make sure if all nodes are visited
            return totalVisited == nums;
        }
};