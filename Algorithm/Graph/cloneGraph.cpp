#include <unordered_map>
#include <vector>
#include <iostream>
class Node {
	public:
		int val;
		std::vector<Node*> neighbors;

		Node()
		{
			this->val = 0;
			this->neighbors = std::vector<Node*>();
		}

		Node(int val)
		{
			this->val = val;
			this->neighbors = std::vector<Node*>();
		}

		Node(int val, std::vector<Node*> neighbors)
		{
			this->val = val;
			this->neighbors = neighbors;
		}
};

class GraphCloner {
	private:
		std::unordered_map<int, Node *> map;

		void cloneUtil(Node* curr)
		{
			int size = curr->neighbors.size();

			for (int i = 0; i < size; i++)
			{
				Node* neighbor = curr->neighbors[i];

				if (map.find(neighbor->val) != map.end())
				{
					curr->neighbors[i] = map[neighbor->val];
				} else
				{
					curr->neighbors[i] = new Node(neighbor->val, neighbor->neighbors);
					map[neighbor->val] = curr->neighbors[i];

					this->cloneUtil(curr->neighbors[i]);
				}
			}
		}

	public:
		Node *clone(Node *node)
		{
			if (node == nullptr)
			{
				return node;
			}

			Node* cloned = new Node(node->val, node->neighbors);
			map[cloned->val] = cloned;

			this->cloneUtil(cloned);

			return cloned;
		}
};

void printGraph(Node* node)
{
	if (node) {
		std::cout << node->val << std::endl;
		for (Node* n : node->neighbors)
		{
			printGraph(n);
		}
	}
}

int main(int argc, char const *argv[])
{
	GraphCloner cloner;

	std::vector<Node*> neighbors;
	neighbors.push_back(new Node(2));
	neighbors.push_back(new Node(3));
	neighbors.push_back(new Node(4));

	Node* node = new Node(1, neighbors);
	
	Node* cloned = cloner.clone(node);

	// print the graph and its children
	printGraph(cloned);
	
	return 0;
}
