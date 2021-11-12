#include <unordered_map>
#include <vector>

class Node {
    public:
        int val;
        std::vector<Node *> neighbors;

        Node()
        {
            val = 0;
            neighbors = vector<Node *>();
        }
        Node(int _val)
        {
            val = _val;
            neighbors = vector<Node *>();
        }
        Node(int _val, vector<Node *> _neighbors)
        {
            val = _val;
            neighbors = _neighbors;
        }
};

class Solution {
    private:
        std::unordered_map<int, Node *> map;

        void cloneUtil(Node* curr)
        {
            int size = curr->neighbors.size();

            for (int i = 0; i < size; i++) {
                Node* neighbor = curr->neighbors[i];

                if (map.find(neighbor->val) != map.end())
                {
                    curr->neighbors[i] = map[neighbor->val];
                } else
                {
                    curr->neighbors[i] = new Node(neighbor->val, neighbor->neighbors);
                    map[neighbor->val] = curr->neighbors[i];

                    cloneUtil(curr->neighbors[i]);
                }
            }
        }

    public:
        Node *cloneGraph(Node *node)
        {
            if (node == nullptr)
            {
                return node;
            }

            Node *clone = new Node(node->val, node->neighbors);
            map[clone->val] = clone;

            cloneUtil(clone);

            return clone;
        }
};