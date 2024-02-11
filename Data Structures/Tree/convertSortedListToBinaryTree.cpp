#include <vector>
#include <iostream>

using namespace std;

/**
  Definition for a binary tree node.
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

/**
  Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

TreeNode* sort(vector<int> &v, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = (start + end + 1) / 2;

    TreeNode* node = new TreeNode(v[mid]);
    node->left = sort(v, start, mid - 1);
    node->right = sort(v, mid + 1, end);

    return node;
}
 
TreeNode* convertSortedListToTree(ListNode *head) {
    ListNode* temp = head;
    vector<int> v;
    
    while (temp) {
        v.push_back(temp->val);
        temp = temp->next;
    }

    return sort(v, 0, v.size() - 1);
}

// Left - Root - Right
void printInOrder(TreeNode* tree)
{
    if (!tree)
        return;

    cout << "(";
    printInOrder(tree->left);
    cout << ")";

    cout << " (";
    cout << tree->val;
    cout << ") ";

    cout << "(";
    printInOrder(tree->right);
    cout << ")";
}

int main(int argc, char const *argv[])
{
    ListNode* l = new ListNode(-10);
    l->next = new ListNode(-3);
    l->next->next = new ListNode(0);
    l->next->next->next = new ListNode(5);
    l->next->next->next->next = new ListNode(9);

    TreeNode* tree = convertSortedListToTree(l);
    printInOrder(tree);
    cout << endl;

    return 0;
}
