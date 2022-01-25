/**
 * @file addOneRowToTree.cpp
 * @author your name (you@domain.com)
 * @brief The adding rule is:
	Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
	cur's original left subtree should be the left subtree of the new left subtree root.
	cur's original right subtree should be the right subtree of the new right subtree root.
	If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.
 * @version 0.1
 * @date 2022-01-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) : val(val) {}
	TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {}
};

class Solution {
	TreeNode* addOneRow(TreeNode* root, int val, int depth, int currDepth = 1, bool isLeft = true) {
		if (depth == currDepth) {
			TreeNode* tr = new TreeNode(val);

			if (isLeft) {
				tr->left = root;
			} else {
				tr->right = root;
			}

			return tr;
		}

		if (!root) {
			return nullptr;
		}

		root->left = addOneRow(root->left, val, depth, currDepth + 1, true);
		root->right = addOneRow(root->right, val, depth, currDepth + 1, false);

		return root;
	}
};