#include <queue>
#include <vector>
#include <set>
#include <functional>
#include <climits>
#include <iostream>

using namespace std;

int getMax(vector<int> nums)
{
	int max = INT_MIN;
	int idxMax = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (max < nums[i])
		{
			max = nums[i];
			idxMax = i;
		}
	}

	return idxMax;
}

template <class T>
struct TreeNode;

template <class T>
class Tree {
	private:
		Tree<T> *left, *right;
		T value;
		int minimum = INT_MAX;

		// Left - Root - Right
		void printInOrderUtil(Tree<T> *tree)
		{
			if (!tree)
				return;

			cout << "(";
			printInOrderUtil(tree->getLeft());
			cout << ")";

			cout << " (";
			cout << tree->getValue();
			cout << ") ";

			cout << "(";
			printInOrderUtil(tree->getRight());
			cout << ")";
		}

		// Root - Left - Right
		void printPreOrderUtil(Tree<T> *tree)
		{
			if (!tree)
				return;

			cout << tree->getValue() << " ";

			cout << "(";
			printPreOrderUtil(tree->getLeft());
			cout << ")";

			cout << " (";
			printPreOrderUtil(tree->getRight());
			cout << ")";
		}

		// Left - Right - Root
		void printPostOrderUtil(Tree<T> *tree)
		{
			if (!tree)
				return;

			cout << "(";
			printPostOrderUtil(tree->getLeft());
			cout << ") ";

			cout << "(";
			printPostOrderUtil(tree->getRight());
			cout << ") ";

			cout << tree->getValue();
		}

		int heightUtil(Tree<T> *root)
		{
			if (!root)
				return -1;

			int left = 1 + heightUtil(root->left);
			int right = 1 + heightUtil(root->right);

			return max(left, right);
		}

		bool isSymmetricUtil(Tree<T> *left, Tree<T> *right)
		{
			// if left has no children and right ones too
			if (left && right)
			{
				if (!left->left && !left->right && !right->left && !right->right)
				{
					if (left->value == right->value)
						return true;
					else
						return false;
				}
				else
				{
					return isSymmetricUtil(left->right, right->left) && isSymmetricUtil(left->left, right->right);
				}
			}
			else if (!left && !right)
				return true;
			else
				return false;
		}

		bool isSubTreeHelper(Tree<T> *tree, Tree<T> *subTree)
		{
			if (!tree && !subTree)
			{
				return true;
			}

			if ((!tree && subTree) || (tree && !subTree))
			{
				return false;
			}

			bool isSame = tree->getValue() == subTree->getValue();
			if (isSame)
			{
				bool isSameLeft = isSubTreeHelper(tree->getLeft(), subTree->getLeft());
				bool isSameRight = isSubTreeHelper(tree->getRight(), subTree->getRight());

				return isSame && isSameRight && isSameLeft;
			}

			return isSame;
		}

		bool hasPathSumUtil(Tree<T> *root, int targetSum, int count = 0)
		{
			if (root)
			{
				int sum = count + root->getValue();

				if (!root->getLeft() && !root->getRight())
				{
					return sum == targetSum;
				}

				return hasPathSumUtil(root->left, targetSum, sum) || hasPathSumUtil(root->right, targetSum, sum);
			}

			return false;
		}

	public:
		Tree(T value)
		{
			this->value = value;
			this->left = nullptr;
			this->right = nullptr;
		}

		Tree<T> *getLeft() const
		{
			return this->left;
		}

		Tree<T> *getRight() const
		{
			return this->right;
		}

		void setRight(Tree<T> *tree)
		{
			this->right = tree;
		}

		void setLeft(Tree<T> *tree)
		{
			this->left = tree;
		}

		T getValue()
		{
			return this->value;
		}

		void insert(T newVal)
		{
			queue<Tree<T> *> queue;

			queue.push(this);

			while (!queue.empty())
			{
				Tree<T> *tree = queue.front();
				T value = tree->getValue();
				queue.pop();

				if (value < newVal)
				{
					Tree<T> *right = tree->getRight();
					if (right)
					{
						queue.push(right);
					}
					else
					{
						tree->setRight(new Tree<T>(newVal));
					}
				}
				else
				{
					Tree<T> *left = tree->getLeft();
					if (left)
					{
						queue.push(left);
					}
					else
					{
						tree->setLeft(new Tree<T>(newVal));
					}
				}
			}
		}

		void printInOrder()
		{
			printInOrderUtil(this);
			cout << endl;
		}

		void printPreOrder()
		{
			printPreOrderUtil(this);
			cout << endl;
		}

		void printPostOrder()
		{
			printPostOrderUtil(this);
			cout << endl;
		}

		vector<T> largestValuesInTreeRows(Tree<T> *t)
		{
			vector<T> vec;
			queue<Tree<T> *> q;

			if (!t)
				return vec;
			q.push(t);

			while (!q.empty())
			{
				Tree<T> *tr = q.front();
				Tree<T> *tr2 = nullptr;
				q.pop();

				Tree<T> *left = tr->left;
				Tree<T> *right = tr->right;

				if (q.empty())
				{
					vec.push_back(tr->value);

					if (left)
						q.push(left);
					if (right)
						q.push(right);
				}
				else
				{
					// vector to save subtree in same depth
					vector<Tree<T> *> vec2;

					// push tree with same depth
					while (!q.empty())
					{
						vec2.push_back(q.front());
						q.pop();
					}

					if (left)
						q.push(left);
					if (right)
						q.push(right);

					// get maximum in same depth
					int max = tr->value;
					for (auto i : vec2)
					{
						Tree<T> *temp = i;
						left = temp->left;
						right = temp->right;

						int val = temp->value;
						if (max < val)
							max = val;

						if (left)
							q.push(left);
						if (right)
							q.push(right);
					}

					vec.push_back(max);
				}
			}

			return vec;
		}

		/**
		 * @brief Print level order using BFS style.
		 * @return void
		 */
		void levelOrder()
		{
			queue<Tree<T> *> q;
			q.push(this);

			while (!q.empty())
			{
				Tree<T> *t = q.front();
				q.pop();

				cout << t->getValue() << " ";

				if (t->left)
				{
					q.push(t->left);
				}

				if (t->right)
				{
					q.push(t->right);
				}
			}
		}

		/**
		 * @brief Grouping tree node with same level in same array bucket.
		 *
		 * @return vector< vector<T> >
		 */
		vector<vector<T>> groupLevelOrder()
		{
			queue<TreeNode<T>> q;
			vector<vector<T>> res;

			if (this == nullptr)
			{
				return res;
			}

			q.push(TreeNode<T>(this, 0));

			while (!q.empty())
			{
				TreeNode<T> t = q.front();
				Tree<T> *tree = t.tree;
				int level = t.level;

				q.pop();

				if (tree)
				{
					vector<T> vec;

					if (level == 0)
					{
						vec.push_back(tree->getValue());
					}
					else
					{
						if (level + 1 <= res.size())
						{
							vec = res.at(level);
							vec.push_back(tree->getValue());
						}
						else
						{
							vec.push_back(tree->getValue());
						}
					}

					Tree<T> *left = tree->getLeft();
					Tree<T> *right = tree->getRight();
					if (left)
					{
						q.push(TreeNode<T>(left, level + 1));
					}

					if (right)
					{
						q.push(TreeNode<T>(right, level + 1));
					}

					if (vec.size() > 0)
					{
						if (level + 1 <= res.size())
						{
							res[level] = vec;
						}
						else
						{
							res.push_back(vec);
						}
					}
				}
			}

			return res;
		}

		int height()
		{
			return heightUtil(this);
		}

		int minimumHeight(Tree *tree, int depth = 1)
		{
			if (depth == 1)
			{
				tree = this->root;
			}

			if (tree)
			{
				if (!tree->left && !tree->right)
				{
					minimum = min(minimum, depth);
				}

				this->minimumHeight(tree->left, depth + 1);
				this->minimumHeight(tree->right, depth + 1);

				return minimum;
			}

			return 0;
		}

		bool isSymmetric()
		{
			if (this->getLeft() && this->getRight())
			{
				bool isSymmetric = isSymmetricUtil(this->getLeft(), this->getRight());

				return isSymmetric;
			}
			else if (!this->getLeft() && !this->getRight())
				return true;
			else
				return false;
		}

		void search(T value)
		{
			// Do search algo
		}

		static bool isBSTree(Tree<T> *tree, int max = INT_MAX, int min = INT_MIN)
		{
			if (tree == nullptr)
				return true;

			if ((min != INT_MIN && tree->getValue() <= min) || (max != INT_MAX && max <= tree->getValue()))
			{
				return false;
			}

			if (isBSTree(tree->getLeft(), tree->getValue(), min) && isBSTree(tree->getRight(), max, tree->getValue()))
			{
				return true;
			}

			return false;
		}

		Tree<T> *constructBinaryTreeFromVector(vector<int> &nums)
		{
			if (nums.size() == 0)
				return nullptr;

			int idxMax = getMax(nums);
			vector<int> arr1 = {nums.begin(), nums.begin() + idxMax};
			vector<int> arr2 = {nums.begin() + idxMax + 1, nums.end()};

			Tree<T> *root = new Tree<T>(nums.at(idxMax));

			root->left = constructBinaryTreeFromVector(arr1);
			root->right = constructBinaryTreeFromVector(arr2);

			return root;
		}

		/**
		 * @brief Given the another tree, return true if the tree is subtree.
		 * 
		 * @param subTree 
		 * @return true 
		 * @return false 
		 */
		bool isSubTree(Tree<T> *subTree)
		{
			queue<Tree<T> *> q;
			q.push(this);

			bool isSubTree = false;
			while (!q.empty() && !isSubTree)
			{
				Tree<T> *tree = q.front();
				q.pop();

				Tree<T> *left = tree->getLeft();
				Tree<T> *right = tree->getRight();

				if (left)
				{
					q.push(left);
				}

				if (right)
				{
					q.push(right);
				}

				isSubTree = isSubTreeHelper(tree, subTree);
			}

			return isSubTree;
		}

		/**
		 * @brief Given an integer target value, return true if the tree has a root-to-leaf
		 * 		  such that adding up all the values along the path equals to `targetSum`
		 * 
		 * @param targetSum 
		 * @return true 
		 * @return false 
		 */
		bool hasPathSum(int targetSum)
		{
			return hasPathSumUtil(this->front(), targetSum);
		}

		/**
		 * @brief Given another tree, return true if the another tree is same with this tree
		 * 
		 * @param anotherTree
		 * @param tree 
		 * @param isRoot
		 * @return true 
		 * @return false 
		 */
		bool isSame(Tree<T>* anotherTree, Tree<T>* tree = nullptr, bool isRoot = true)
		{
			if (isRoot) {
				tree = this;
			}

			if (tree == nullptr && anotherTree == nullptr) {
				return true;
			}

			if (!tree || !anotherTree) {
				return false;
			}

			bool isSameVal = tree->getValue() == anotherTree->getValue();
			if (isSameVal) {
				return isSame(anotherTree->getLeft(), tree->getLeft(), false) && isSame(anotherTree->getRight(), tree->getRight(), false);
			}

			return false;
		}

		/**
		 * @brief Print right view of Tree
		 *
		 */
		void rightView()
		{
			std::function<void(Tree<T> *, vector<int> &, int)> traverse;
			int maxLevel = 0;

			traverse = [&traverse, &maxLevel](Tree<T> *node, vector<int> &res, int level)
			{
				if (node)
				{
					if (maxLevel < level)
					{
						maxLevel++;
						res.push_back(node->getValue());
					}

					traverse(node->getRight(), res, level + 1);
					traverse(node->getLeft(), res, level + 1);
				}
			};

			vector<int> v;
			traverse(this, v, 1);

			for (auto num : v)
			{
				cout << num << " ";
			}
			cout << endl;
		}

		/**
		 * @brief Print left view of tree
		 *
		 */
		void leftView()
		{
			function<void(Tree<T> *, int, vector<int> &)> traverse;
			int maxLevel = 0;
			traverse = [&traverse, &maxLevel](Tree<T> *node, int level, vector<int> &res)
			{
				if (node)
				{
					if (maxLevel < level)
					{
						maxLevel++;
						cout << node->getValue() << " ";
					}

					traverse(node->getLeft(), level + 1, res);
					traverse(node->getRight(), level + 1, res);
				}
			};

			vector<int> v;
			traverse(this, 1, v);

			for (auto num : v)
			{
				cout << num << " ";
			}

			cout << endl;
		}

		/**
		 * @brief Get max depth of Tree
		 *
		 * @param root
		 * @param isRoot
		 * @return int the max depth of Tree
		 */
		int maxDepth(Tree<T> *root = nullptr, bool isRoot = true)
		{
			if (isRoot)
			{
				root = this;
			}

			if (root)
			{
				Tree<T> *left = root->getLeft();
				Tree<T> *right = root->getRight();

				if (!left && !right)
				{
					return 1;
				}

				int maxLeft = 1 + maxDepth(left, false);
				int maxRight = 1 + maxDepth(right, false);

				return max(maxLeft, maxRight);
			}

			return 0;
		}
};

template <class T>
struct TreeNode
{
	Tree<T> *tree;
	int level;

	TreeNode(Tree<T> *t, int l) : tree(t), level(l) {}
};

int main(int argc, const char **argv)
{
	Tree<int> tree(3);
	tree.insert(1);
	tree.insert(2);
	tree.insert(4);

	// (() (1) (() (2) ())) (3) (() (4) ())

	//          3
	//      1       4
	// null   2

	// output left view: 3 1 2
	// output right view: 3 4 2

	tree.printInOrder();
	// tree.printPostOrder();
	// tree.levelOrder();
	cout << "Is Symetric? " << tree.isSymmetric() << endl;

	// Print right view of Tree
	tree.rightView();

	// Print left view of Tree
	tree.leftView();

	vector<vector<int>> res = tree.groupLevelOrder();

	cout << "\nGroup level order: " << endl;
	for (auto v : res)
	{
		for (int val : v)
		{
			cout << val << " ";
		}

		cout << endl;
	}

	cout << "\nMax Depth of Tree: " << tree.maxDepth() << endl;

	cout << "\nIs Same Tree?: " << ((tree.isSame(&tree) == 1) ? "Same" : "Not Same") << endl;

	return 0;
}