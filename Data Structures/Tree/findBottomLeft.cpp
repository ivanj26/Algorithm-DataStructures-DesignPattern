struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
	int val;
	int level = INT_MIN;
public:
	void find(TreeNode* root, int lvl = 0) {
		if (root) {
			find(root->left, lvl + 1);
			find(root->right, lvl + 1);
			
			if (lvl > this->level) {
				this->val = root->val;
				this->level = lvl;
			}
		}
	}
	
	int findBottomLeftValue(TreeNode* root) {
		find(root);
		
		return level == INT_MIN ? root->val : val;
	}
};