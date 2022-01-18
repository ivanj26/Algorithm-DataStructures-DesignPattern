/**
 * @file invertTree.cpp
 * @author Ivan Jonathan
 * @brief Given the root of a binary tree, invert the tree, and return its root.
 * @version 0.1
 * @date 2022-01-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	void invertTreeHelper(TreeNode *root)
	{
		if (root)
		{
			TreeNode *left = root->left;
			TreeNode *right = root->right;

			root->left = right;
			root->right = left;

			invertTreeHelper(root->left);
			invertTreeHelper(root->right);
		}
	}

	TreeNode *invertTree(TreeNode *root)
	{
		invertTreeHelper(root);

		return root;
	}
};