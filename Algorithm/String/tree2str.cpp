#include <string>

using namespace std;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;

	TreeNode(int val) {
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};

class Solution {
	public:
		string tree2str(TreeNode* root) {
			if (!root) {
				return "";
			}

			if (root->left || root->right) {
				string res = to_string(root->val) + "(" + tree2str(root->left) + ")";

				if (root->right) {
					res += "(" + tree2str(root->right) + ")";
				}

				return res;
			}

			return to_string(root->val);
		}
};