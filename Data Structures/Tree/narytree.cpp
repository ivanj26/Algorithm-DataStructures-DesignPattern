#include <vector>

using namespace std;

class Tree {
	private:
		int val;
		vector<Tree*> children;
	public:
		int getValue() {
			return val;
		}

		vector<Tree*> getChildren() const {
			return children;
		}
};

class Solution {
	private:
		vector<int> v;
		int depthMax;

		void preorderUtil(Tree* root) {
			if (!root) {
				return;
			}

			v.push_back(root->getValue());

			for (Tree* child : root->getChildren()) {
				preorderUtil(child);
			}
		}

		void postorderUtil(Tree* root) {
			if (!root) {
				return;
			}

			for (Tree* child : root->getChildren()) {
				postorderUtil(child);
			}

			v.push_back(root->getValue());
		}

		int maxDepthUtil(Tree* root, int level = 0) {
			if (!root) {
				return level;
			}

			for (Tree* child : root->getChildren()) {
				this->depthMax = max(this->depthMax, 1 + this->maxDepthUtil(child, level + 1));
			}

			return level;
		}

	public:
		Solution() {
			this->depthMax = 0;
		}

		vector<int> preorder(Tree* root) {
			preorderUtil(root);

			return v;
		}

		vector<int> postorder(Tree* root) {
			postorderUtil(root);

			return v;
		}

		int maxDepth(Tree* root) {
			if (!root) {
				return 0;
			}

			if (root->getChildren().size() == 0) {
				return 1;
			}

			maxDepthUtil(root);

			return this->depthMax;
		}
};