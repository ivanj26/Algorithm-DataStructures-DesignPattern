#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Tree
{
	int level;
	TreeNode *node;
	Tree(int level, TreeNode *node) : level(level), node(node) {}
};

class Solution {
	public:
		vector<int> largestValues(TreeNode* root) {
			if (!root) {
				return {};
			}

			queue<Tree> q;
			vector<int> ans;

			// insert the root
			q.push(Tree(1, root));

			while (!q.empty()) {
				Tree tr = q.front();
				int level = tr.level;
				TreeNode* node = tr.node;

				if (level > ans.size()) {
					ans.push_back(node->val);
				} else {
					// level <= ans.size()
					int val2 = ans[level - 1];
					int val = node->val;
					if (val > val2) {
						ans[level - 1] = val;
					}
				}

				TreeNode* left = node->left;
				TreeNode* right = node->right;

				if (left) q.push(left);
				if (right) q.push(right);

				q.pop();
			}

			return ans;
		}
};