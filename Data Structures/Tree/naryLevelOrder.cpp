#include <queue>
#include <vector>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

struct Tree {
	int level;
	Node* node;
	
	Tree(int level, Node* node) {
		this->level = level;
		this->node = node;
	}
};

class Solution {
public:
	vector<vector<int>> levelOrder(Node* root) {
		// initialize queue data structure
		queue<Tree*> q;
		vector<vector<int>> results;
		int maxLevel = INT_MIN;
		
		// insert into queue
		q.push(new Tree(0, root));
		
		// check if queue is not empty, then do a loop
		while (!q.empty()) {
			Tree* tr = q.front();
			
			Node* node = tr->node;
			int levelParent = tr->level;
			
			// if node is exists, push into the results
			if (node) {
				if (maxLevel < levelParent) {
					maxLevel = levelParent;
				}

				if (results.size() <= maxLevel) {
					results.push_back({});
				}
				results[levelParent].push_back(node->val);
			
				for (Node* child : node->children) {
					q.push(new Tree(levelParent + 1, child));
				}
			}
			
			
			q.pop();
		}
		
		return results;
	}
};