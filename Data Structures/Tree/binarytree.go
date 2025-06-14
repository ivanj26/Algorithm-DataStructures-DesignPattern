package main

import "fmt"

type TreeNode struct {
	Left  *TreeNode
	Right *TreeNode
	Val   int
}

func (t *TreeNode) inorderUtil(root *TreeNode, output *[]int) {
	if root == nil {
		return
	}

	// Left subtree -> Root -> Right subtree

	left := root.Left
	if left != nil {
		t.inorderUtil(left, output)
	}

	*output = append(*output, root.Val)

	right := root.Right
	if right != nil {
		t.inorderUtil(right, output)
	}
}

func (t *TreeNode) preorderUtil(root *TreeNode, output *[]int) {
	if root == nil {
		return
	}

	// Root -> Left subtree -> Right subtree
	*output = append(*output, root.Val)

	if left := root.Left; left != nil {
		t.preorderUtil(left, output)
	}

	if right := root.Right; right != nil {
		t.preorderUtil(right, output)
	}
}

func (t *TreeNode) postorderUtil(root *TreeNode, output *[]int) {
	if root == nil {
		return
	}

	// Left subtree -> Right subtree -> Root
	if left := root.Left; left != nil {
		t.preorderUtil(left, output)
	}

	if right := root.Right; right != nil {
		t.preorderUtil(right, output)
	}

	*output = append(*output, root.Val)
}

func (t *TreeNode) Inorder() []int {
	var (
		output []int
		root   *TreeNode = t
	)

	t.inorderUtil(root, &output)
	return output
}

func (t *TreeNode) Preorder() []int {
	var (
		output []int
		root   *TreeNode = t
	)
	t.preorderUtil(root, &output)

	return output
}

func (t *TreeNode) Postorder() []int {
	var (
		output []int
		root   *TreeNode = t
	)
	t.postorderUtil(root, &output)

	return output
}

func main() {
	t := &TreeNode{
		Left: nil,
		Right: &TreeNode{
			Val: 2,
			Left: &TreeNode{
				Val: 3,
			},
		},
		Val: 1,
	}

	out := t.Inorder()
	for _, el := range out {
		fmt.Printf("%d ", el)
	}
	fmt.Println()
}
