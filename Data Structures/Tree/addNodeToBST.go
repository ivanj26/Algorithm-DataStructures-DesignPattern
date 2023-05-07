package main

type TreeNode struct {
	Left  *TreeNode
	Right *TreeNode
	Val   int
}

func insertNodeIntoBST(root *TreeNode, val int) *TreeNode {
	return addNode(root, val)
}

func addNode(node *TreeNode, val int) *TreeNode {
	if node == nil {
		return &TreeNode{
			Left:  nil,
			Right: nil,
			Val:   val,
		}
	}

	switch {
	case node.Val > val:
		{
			node.Left = addNode(node.Left, val)
		}
	case node.Val < val:
		{
			node.Right = addNode(node.Right, val)
		}
	case node.Val == val:
		{
			return node
		}
	}

	return node
}
