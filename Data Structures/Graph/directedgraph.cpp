#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

template <class T>
class DirectedGraph {
    private:
        int nbOfNodes;
        vector<T> *adjNodes;
    public:
        DirectedGraph(long nbOfNodes) {
            this->nbOfNodes = nbOfNodes;
            adjNodes = new vector<T>[nbOfNodes];
        }

        DirectedGraph() {}

        ~DirectedGraph() {
            delete[] adjNodes;
        }

        void addAdjNodes(long from, long to) {
            adjNodes[from].push_back(to);
        }

        void removeAdjNodes(long from, long to) {
            adjNodes[from].erase(
                std::remove(adjNodes[from].begin(), adjNodes[from].end(), to),
                adjNodes[from].end()
            );
        }

        void print() {
            for (int i = 0; i < nbOfNodes; i++)
            {
                cout << i;
                for (auto x: adjNodes[i])
                {
                    cout << " -> " << x;
                }

                cout << endl;
            }
        }
        
        template <class DirectedGraph>
        friend class BFSAlgorithm;
};