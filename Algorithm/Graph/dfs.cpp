#include "../../Data Structures/Graph/directedgraph.cpp"
#include <vector>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class DFSAlgorithm {
    private:
        DirectedGraph<T> g;
    public:
        DFSAlgorithm(const DirectedGraph<T>& g){
            this->g = g;
        }

        //Iterative depth first search -> using stack
        void doFromNode(T s) {
            long size = g.nbOfNodes;
            vector<T> *vec = g.adjNodes;

            bool *visited = new bool[size];
            for (long i = 0; i < size; i++)
            {
                visited[i] = false;
            }

            stack<T> st;
            st.push(s);

            while (!st.empty()) {
                T out = st.top();
                cout << out << " ";

                st.pop();
                visited[(long) out] = true;

                for (auto i : vec[(long) out]) {
                    if (!visited[(long) i]) {
                        st.push(i);
                    }
                }
            }

            cout << endl;
            delete[] visited;
        }
};

int main(int argc, const char** argv) {
    DirectedGraph<int> g(5);
    g.addAdjNodes(1, 0);
    g.addAdjNodes(0, 2);
    g.addAdjNodes(2, 1);
    g.addAdjNodes(0, 3);
    g.addAdjNodes(1, 4);

    DFSAlgorithm<int> dfs(g);
    dfs.doFromNode(0);

    return 0;
}