package main

type Node struct {
	Val   int
	Left  *Node
	Right *Node
	Next  *Node
}

func populateNextPointer(node *Node, parent *Node) {
	// Basis of recursion - If the tree node is terminal/leaf
	if node == nil {
		return
	}

	if parent == nil {
		node.Next = nil
	} else {
		if parent.Next == nil {
			if parent.Left == node {
				node.Next = parent.Right
			} else {
				node.Next = nil
			}
		} else { // if parent.Next is not nil
			if parent.Left == node {
				node.Next = parent.Right
			} else {
				node.Next = parent.Next.Left
			}
		}
	}

	populateNextPointer(node.Left, node)
	populateNextPointer(node.Right, node)
}

func connect(root *Node) *Node {
	populateNextPointer(root, nil)

	return root
}
