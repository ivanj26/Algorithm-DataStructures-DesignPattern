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
private:
	int min = INT_MAX;
	int prev = INT_MAX;

public:
	int minDiff(TreeNode *root)
	{
		if (root->left)
		{
			minDiff(root->left);
		}

		if (prev != INT_MAX)
		{
			this->min = std::min(min, abs(prev - root->val));
		}

		prev = root->val;
		if (root->right)
		{
			minDiff(root->right);
		}

		return this->min;
	}
};