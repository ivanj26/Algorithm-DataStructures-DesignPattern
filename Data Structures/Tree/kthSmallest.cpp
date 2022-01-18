#include <algorithm>
#include <vector>
#include <set>
#include <functional>

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

		/**
		 * @brief kth smallest element with memory optimization
		 * 
		 */
		int kthSmallest2(TreeNode* root, int k) {
			std::function<void(TreeNode*, int)> func;
			int result = INT_MIN;
			int count = 0;

			// function to traverse the tree inorder
			func = [&func, &result, &count](TreeNode* node, int _k) {
				if (!node) {
					return;
				}

				func(node->left, _k);
				count++;

				if (count == _k) {
					result = node->val;
					return;
				}

				if (count > _k) {
					return;
				}

				func(node->right, _k);
			};

			func(root, k);

			return result;
		}
};