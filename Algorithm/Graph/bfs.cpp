#include "../../Data Structures/Graph/directedgraph.cpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

template <class T>
class BFSAlgorithm {
    private:
        DirectedGraph<T> g;
    public:
        BFSAlgorithm(const DirectedGraph<T>& g) {
            this->g = g;
        }

        void doFromNode(T s) {
            long size = g.nbOfNodes;
            vector<T> *vec = g.adjNodes;

            bool *visited = new bool[size];
            for (long i = 0; i < size; i++)
            {
                visited[i] = false;
            }

            visited[(long) s] = true;

            queue<T> q;
            q.push((long) s);

            while (!q.empty()) {
                s = q.front();
                cout << s << " ";
                q.pop();

                for (auto i: vec[(long)s])
                {
                    if (!visited[(long)i]) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }

            cout << endl;

            delete[] visited;
        }
};

int main(int argc, const char** argv) {
    DirectedGraph<int> g(5);
    g.addAdjNodes(0, 1);
    g.addAdjNodes(0, 2);
    g.addAdjNodes(1, 2);
    g.addAdjNodes(2, 0);
    g.addAdjNodes(2, 3);
    g.addAdjNodes(3, 3);

    BFSAlgorithm<int> bfs(g);
    bfs.doFromNode(2);

    return 0;
}