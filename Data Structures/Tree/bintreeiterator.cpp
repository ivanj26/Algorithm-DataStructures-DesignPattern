#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}

class BSTIterator
{
	private:
		vector<int> v;
		int idx;

		void inOrder(TreeNode *root)
		{
			if (!root)
				return;

			inOrder(root->left);
			v.push_back(root->val);
			inOrder(root->right);
		}

	public:
		BSTIterator(TreeNode *root)
		{
			inOrder(root);
			idx = 0;
		}

		int next()
		{
			int val = v[idx];
			idx++;

			return val;
		}

		bool hasNext()
		{
			if (idx < v.size())
				return true;

			return false;
		}
};