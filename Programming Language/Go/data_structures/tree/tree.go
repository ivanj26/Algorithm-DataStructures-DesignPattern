package main

import "fmt"

type Tree struct {
	Left  *Tree
	Right *Tree
	Val   byte
}

// Left - Root - Right
func (t *Tree) Inorder() []byte {
	var (
		inOrderUtilFunc func(node *Tree, arr *[]byte)
		result          []byte
	)

	inOrderUtilFunc = func(node *Tree, arr *[]byte) {
		if node == nil {
			return
		}

		// Traverse and recursive to Left hand side of Tree
		inOrderUtilFunc(node.Left, arr)

		// Push the element into array
		*arr = append(*arr, node.Val)

		// Traverse again to Right hand side of Tree
		inOrderUtilFunc(node.Right, arr)
	}

	inOrderUtilFunc(t, &result)
	return result
}

// Left - Right - Root
func (t *Tree) Postorder() []byte {
	var (
		postOrderUtilFunc func(node *Tree, arr *[]byte)
		result            []byte
	)

	postOrderUtilFunc = func(node *Tree, arr *[]byte) {
		if node == nil {
			return
		}

		// Traverse and recursive to Left hand side of Tree
		postOrderUtilFunc(node.Left, arr)

		// Traverse again to Right hand side of Tree
		postOrderUtilFunc(node.Right, arr)

		// Push the element into array
		*arr = append(*arr, node.Val)
	}

	postOrderUtilFunc(t, &result)
	return result
}

// Root - Left - Right
func (t *Tree) Preorder() []byte {
	var (
		preOrderUtilFunc func(node *Tree, arr *[]byte)
		result           []byte
	)

	preOrderUtilFunc = func(node *Tree, arr *[]byte) {
		if node == nil {
			return
		}

		// Traverse and recursive to Left hand side of Tree
		preOrderUtilFunc(node.Left, arr)

		// Traverse again to Right hand side of Tree
		preOrderUtilFunc(node.Right, arr)

		// Push the element into array
		*arr = append(*arr, node.Val)
	}

	preOrderUtilFunc(t, &result)
	return result
}

func (t *Tree) IsLeaf() bool {
	return t.Left == nil && t.Right == nil
}

func (t *Tree) removeLeaf(node *Tree, target byte) *Tree {
	if node == nil {
		return nil
	}

	node.Left = t.removeLeaf(node.Left, target)
	node.Right = t.removeLeaf(node.Right, target)

	if node.IsLeaf() {
		if node.Val == target {
			return nil
		}
	}

	return node
}

func (t *Tree) RemoveLeaf(target byte) {
	t = t.removeLeaf(t, target)
}

func main() {
	tree := Tree{
		Left: nil,
		Right: &Tree{
			Val:   2,
			Right: nil,
			Left: &Tree{
				Val:   3,
				Left:  nil,
				Right: nil,
			},
		},
		Val: 1,
	}

	tree.RemoveLeaf(3)

	bytes := tree.Inorder()
	for _, b := range bytes {
		fmt.Printf("%v ", b)
	}

	fmt.Println()

	bytes = tree.Postorder()
	for _, b := range bytes {
		fmt.Printf("%v ", b)
	}
}
