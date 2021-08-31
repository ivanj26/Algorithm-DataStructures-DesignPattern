#include <iostream>
#include <queue>
using namespace std;

template <class T = int>
class Tree
{
	private:
		Tree<T> *left, *right;
		T info;

	public:
		Tree(T info)
		{
			this->info = info;
			this->left = nullptr;
			this->right = nullptr;
		}

		~Tree()
		{
			delete left;
			delete right;
		}

		void setLeft(Tree<T> *left)
		{
			this->left = left;
		}

		Tree<T> *getLeft()
		{
			return this->left;
		}

		void setRight(Tree<T> *right)
		{
			this->right = right;
		}

		T getInfo() const { return this->info; }

		Tree<T> *getRight()
		{
			return this->right;
		}

		bool isExist(T t)
		{
			if (this == nullptr)
			{
				return false;
			}
			else
			{
				queue<Tree<T> *> q;
				q.push(this);

				while (!q.empty())
				{
					Tree<T> *tr = q.front();
					if (tr->info == t)
					{
						return true;
					}
					// - remove first element
					q.pop();
					// - add child(s)
					if (tr->getLeft() != nullptr)
						q.push(tr->getLeft());
					if (tr->getRight() != nullptr)
						q.push(tr->getRight());
				}
			}

			return false;
		}

		// efficient if t is in leaf / terminal
		static bool isExistRec(T t, Tree<T> *root)
		{
			if (root != nullptr)
			{
				if (root->info == t)
				{
					return true;
				}

				Tree<T> *left = root->left;
				Tree<T> *right = root->right;

				return Tree::isExistRec(t, left) || Tree::isExistRec(t, right);
			}
			else
			{
				return false;
			}
		}
};

template <class T>
void printTree(Tree<T> *tree, int level = 0)
{
	if (tree == nullptr)
		return;

	printTree(tree->getRight(), level + 1);

	if (level != 0)
	{
		for (int i = 0; i < level - 1; i++)
			cout << "\t";
		cout << "|-------" << tree->getInfo() << endl;
	}
	else
	{
		cout << endl;
		cout << tree->getInfo() << endl;
	}
	printTree(tree->getLeft(), level + 1);
}

int main(int argc, char const *argv[])
{
	Tree<int> *root = new Tree<int>(6);
	Tree<int> *tree_7 = new Tree<int>(7);
	Tree<int> *tree_100 = new Tree<int>(100);
	Tree<int> *tree_10 = new Tree<int>(10);
	Tree<int> *tree_8 = new Tree<int>(8);
	Tree<int> *tree_14 = new Tree<int>(14);

	tree_100->setRight(tree_14);
	tree_7->setRight(tree_8);
	tree_7->setLeft(tree_10);

	root->setLeft(tree_7);
	root->setRight(tree_100);

	// print Tree
	// printTree(root);

	// check if exist
	cout << (Tree<int>::isExistRec(14, root) ? "Found" : "Not Found") << endl;

	// clear memory
	delete root;

	return 0;
}
