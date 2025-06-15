package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func insert(root *TreeNode, val int) {
	if val < root.Val {
		if root.Left == nil {
			root.Left = &TreeNode{
				Val:   val,
				Left:  nil,
				Right: nil,
			}
			return
		}

		insert(root.Left, val)
	} else if val > root.Val {
		if root.Right == nil {
			root.Right = &TreeNode{
				Val:   val,
				Left:  nil,
				Right: nil,
			}
			return
		}

		insert(root.Right, val)
	}
}

func bstFromPreorder(preoder []int) *TreeNode {
	var root *TreeNode = &TreeNode{Val: preoder[0]}

	for _, value := range preoder {
		insert(root, value)
	}

	return root
}
