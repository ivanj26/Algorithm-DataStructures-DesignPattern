/**
 * @file findProfessionTree.cpp
 * @author Ivan Jonathan
 * @brief find profession with a given family tree.
 * @version 0.1
 * @date 2021-12-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <string>
#include <assert.h>

using namespace std;

struct TreeNode {
	string job;

	int level;
	int pos;

	TreeNode* left;
	TreeNode* right;

	TreeNode(string job, int level, int pos) : job(job), level(level), pos(pos) {}
};

//     E			level 1
//   E     D		level 2
// E  D  D   E		level 3

TreeNode* constructFamTree(int level, int i = 0, bool isLeft = true, int pos = 1, string parentJob = "Engineer") {
	if (level == i) {
		return nullptr;
	}

	string oppositeJob = parentJob == "Engineer" ? "Doctor" : "Engineer";
	TreeNode *root = new TreeNode(isLeft ? parentJob : oppositeJob, i + 1, pos);

	root->left = constructFamTree(level, i + 1, true, pos + pos - 1, root->job);
	root->right = constructFamTree(level, i + 1, false, pos + pos, root->job);

	return root;
}

string search(TreeNode* root, int level, int pos) {
	if (!root) {
		return "notfound";
	}

	if (root->level == level && pos == root->pos) {
		return root->job;
	}

	string left = search(root->left, level, pos);
	
	if (left != "notfound") {
		return left;
	}

	string right = search(root->right, level, pos);

	return right;
}

string findProfession(int level, int pos) {
	assert(level >= 1);
	assert(pos >= 1);

	TreeNode* root = constructFamTree(level);

	return search(root, level, pos);
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}
