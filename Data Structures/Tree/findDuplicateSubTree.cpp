#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	int val;

	TreeNode(int val) : val(val) {
		this->left = nullptr;
		this->right = nullptr;
	}
};

class Solution {
	private:
		unordered_map<string, int> map;
		vector<TreeNode*> res;

		string inorder(TreeNode* root) {
			if (!root) {
				return "";
			}

			string left = inorder(root->left);
			string right = inorder(root->right);

			string curr = "l" + left + to_string(root->val) + right + "r";
			if (map[curr] == 1) {
				res.push_back(root);
			}

			map[curr]++;
			return curr;
		}
	public:
		vector<TreeNode*> findDuplicateSubTrees(TreeNode* root) {
			inorder(root);
			return res;
		}
};