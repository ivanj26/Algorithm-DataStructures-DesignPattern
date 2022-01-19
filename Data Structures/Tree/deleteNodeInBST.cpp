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
		TreeNode* searchAndDeleteKey (TreeNode* root, int key) {
			if (root) {
				if (root->val == key) {
					TreeNode* left = root->left;
					TreeNode* right = root->right;
					
					// no child condition
					if (!left && !right) {
						return nullptr;
					}
					
					// one child condition
					if (!left || !right) {
						return left ? left : right;
					}
					
					// two children condition
					TreeNode* temp = root->right;
					while(temp->left != NULL) {
						temp = temp->left;
					}
					root->val = temp->val;
					root->right = searchAndDeleteKey(root->right, temp->val);
				} else if (root->val > key) {
					root->left = searchAndDeleteKey(root->left, key);
				} else {
					root->right = searchAndDeleteKey(root->right, key);
				}
			}
			
			return root;
		}

	public:
		TreeNode* deleteNode(TreeNode* root, int key) {
			return searchAndDeleteKey(root, key);
		}
};
