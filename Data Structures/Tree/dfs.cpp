#include <set>
#include <iostream>
using namespace std;

struct Tree {
	int val;
	Tree* left;
	Tree* right;

	Tree(int v) {
		this->val = v;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class DFS {
	private:
		set<Tree*> visited;
		Tree* root;

		void printUtil(Tree* tree) {
			if (tree) {
				bool isVisited = visited.find(tree) != visited.end();
				if (isVisited) {
					// nothing
				} else {
					cout << tree->val << " ";

					visited.insert(tree);

					Tree* left = tree->left;
					Tree* right = tree->right;

					this->printUtil(left);
					this->printUtil(right);
				}
			}
		}
	public:
		DFS(Tree* root) {
			this->root = root;
		}

		void print() {
			printUtil(root);
		}
};

void deleteTree(Tree** tree) {
	if (*tree) {
		Tree* right = (*tree)->right;
		Tree* left = (*tree)->left;

		delete *tree;
		deleteTree(&left);
		deleteTree(&right);
	}
}

int main(int argc, char const *argv[])
{
	Tree* root = new Tree(1);
	root->left = new Tree(2);
	root->right = new Tree(6);
	root->left->left = new Tree(3);
	root->left->right = new Tree(5);

	root->right->left = new Tree(7);
	root->right->right = new Tree(9);

	DFS dfs(root);
	dfs.print();

	deleteTree(&root);

	return 0;
}
