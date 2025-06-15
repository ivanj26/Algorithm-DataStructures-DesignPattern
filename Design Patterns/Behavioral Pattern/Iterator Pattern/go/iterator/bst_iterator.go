package main

import "math"

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type BSTIterator struct {
	items   []int
	currIdx int
}

func inorder(root *TreeNode, items *[]int) {
	if root != nil {
		inorder(root.Left, items)
		*items = append(*items, root.Val)
		inorder(root.Right, items)
	}
}

func Constructor(root *TreeNode) BSTIterator {
	var items []int
	inorder(root, &items)

	return BSTIterator{
		items:   items,
		currIdx: 0,
	}
}

func (this *BSTIterator) Next() int {
	if this.currIdx < len(this.items) {
		curr := this.items[this.currIdx]
		this.currIdx++
		return curr
	}

	return math.MinInt32 // no element in the next pointer
}

func (this *BSTIterator) HasNext() bool {
	return this.currIdx < len(this.items)
}
