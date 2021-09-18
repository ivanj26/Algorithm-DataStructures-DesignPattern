#include <unordered_map>
using namespace std;

class Node
{
	int data;
	Node *left;
	Node *right;
};

Node *searchBinTree(Node *node, int val, unordered_map<Node *, Node *> &map)
{
	if (node)
	{
		if (node->data == val)
		{
			if (map.size() == 0)
			{
				map.insert(make_pair(node, nullptr));
			}

			return node;
		}
		if (node->data < val)
		{
			if (map.size() == 0)
			{
				map.insert(make_pair(node, nullptr));
			}

			if (node->right)
			{
				map.insert(make_pair(node->right, node));
			}
			return searchBinTree(node->right, val, map);
		}
		else
		{
			if (map.size() == 0)
			{
				map.insert(make_pair(node, nullptr));
			}

			if (node->left)
			{
				map.insert(make_pair(node->left, node));
			}
			return searchBinTree(node->left, val, map);
		}
	}

	return nullptr;
}

Node *lca(Node *root, int v1, int v2)
{
	unordered_map<Node *, Node *> map1;
	unordered_map<Node *, Node *> map2;

	Node *found1 = searchBinTree(root, v1, map1);
	Node *found2 = searchBinTree(root, v2, map2);

	int size1 = map1.size();
	int size2 = map2.size();

	Node *curr1 = found1;
	while (size1 > size2)
	{
		curr1 = map1[curr1];
		size1--;
	}

	Node *curr2 = found2;
	while (size2 > size1)
	{
		curr2 = map2[curr2];
		size2--;
	}

	while (size1 > 0)
	{
		if (curr1 && curr2)
		{
			if (curr1 == curr2)
			{
				return curr1;
			}
		}

		Node *parent1 = map1[curr1];
		Node *parent2 = map2[curr2];

		if (!parent1 && !parent2)
		{
			if (curr1 == curr2)
			{
				return curr1;
			}
		}

		if (parent1 == parent2)
		{
			return parent1;
		}

		curr1 = parent1;
		curr2 = parent2;

		size1--;
	}

	return nullptr;
}