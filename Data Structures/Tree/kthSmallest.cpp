#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),  right(right) {};
};

class Solution {
	private:
		vector<int> v;
		set<TreeNode*> visited;

		void visit(TreeNode* node) {
			if (node && visited.find(node) == visited.end()) {
				visited.insert(node);

				v.push_back(node->val);

				visit(node->left);
				visit(node->right);
			}
		}

	public:
		int kthSmallest(TreeNode* root, int k) {
			visit(root);

			sort(v.begin(), v.end());

			return v.at(k - 1);
		}
};