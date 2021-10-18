#include <stack>
#include <set>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 *
 * */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	public:
		unsigned int sumNumUtil(TreeNode *root, stack<int> s, set<TreeNode *> visited)
		{
			if (root)
			{
				bool isVisited = visited.find(root) != visited.end();
				if (!isVisited)
				{
					s.push(root->val);
					visited.insert(root);
				}

				if (!root->left && !root->right)
				{
					unsigned int count = 0;
					unsigned int base = 1;

					while (!s.empty())
					{
						int val = s.top();

						count += (base * val);
						base *= 10;

						s.pop();
					}

					return count;
				}

				return sumNumUtil(root->left, s, visited) + sumNumUtil(root->right, s, visited);
			}

			return 0;
		}

		unsigned int sumNumbers(TreeNode *root)
		{
			if (root)
			{
				if (!root->left && !root->right)
				{
					return root->val;
				}

				stack<int> s;
				set<TreeNode *> visited;

				// - push root value into stack
				s.push(root->val);
				visited.insert(root);

				return sumNumUtil(root->left, s, visited) + sumNumUtil(root->right, s, visited);
			}

			return 0;
		}
};

int main(int argc, char const *argv[])
{
	Solution sol;

	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	cout << sol.sumNumbers(root) << endl;
	return 0;
}
