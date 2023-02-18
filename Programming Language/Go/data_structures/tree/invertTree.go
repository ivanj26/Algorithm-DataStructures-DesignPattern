package main

type TreeNode struct {
	Left  *TreeNode
	Right *TreeNode
	Val   int
}

func invertTreeUtil(root *TreeNode) {
	// Basis recursion 1: node is null or not
	if root == nil {
		return
	}

	// Basis recursion 2: Check if node is terminal (doesn't have left & right child)
	if root.Left != nil && root.Right != nil {
		return
	}

	tmp := root.Right

	// Switch between those two children
	root.Right = root.Left
	root.Left = tmp

	invertTreeUtil(root.Left)
	invertTreeUtil(root.Right)
}

func invertTree(root *TreeNode) *TreeNode {
	invertTreeUtil(root)

	return root
}
