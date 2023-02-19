package main

// Problem: https://leetcode.com/problems/find-mode-in-binary-search-tree/

// Given the root of a binary search tree (BST) with duplicates,
// return all the mode(s) (i.e., the most frequently occurred element) in it.

// If the tree has more than one mode, return them in any order.

// Assume a BST is defined as follows:
// - The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// - The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// - Both the left and right subtrees must also be binary search trees.

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func dfs(root *TreeNode, mp *map[int]int, max *int) {
	if root == nil {
		return
	}

	_, found := (*mp)[root.Val]
	if !found {
		(*mp)[root.Val] = 1
	} else {
		(*mp)[root.Val] += 1
	}

	// Replace max value if greater than max
	if *max < (*mp)[root.Val] {
		*max = (*mp)[root.Val]
	}

	// Traverse to another child nodes
	dfs(root.Left, mp, max)
	dfs(root.Right, mp, max)
}

func findMode(root *TreeNode) []int {
	mp := make(map[int]int)
	max := 0

	dfs(root, &mp, &max)

	results := []int{}
	for i, freq := range mp {
		if max == freq {
			results = append(results, i)
		}
	}

	return results
}
