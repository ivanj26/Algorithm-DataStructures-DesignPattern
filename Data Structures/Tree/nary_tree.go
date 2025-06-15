package main

import "math"

type Node struct {
	Val      int
	Children []*Node
}

type Queue struct {
	items []int
}

func NewQueue() *Queue {
	return &Queue{
		items: make([]int, 0),
	}
}

func (q *Queue) Push(item int) {
	q.items = append(q.items, item)
}

func (q *Queue) IsEmpty() bool {
	return len(q.items) == 0
}

func (q *Queue) Front() int {
	if q.IsEmpty() {
		return math.MinInt32
	}
	return q.items[0]
}

func (q *Queue) Pop() {
	if q.IsEmpty() {
		return
	}
	q.items = q.items[1:]
}

func traverse(root *Node, q *Queue) {
	// Root -> Left -> Right
	if root != nil {
		q.Push(root.Val)

		for _, child := range root.Children {
			traverse(child, q)
		}
	}
}

func traversePostorder(root *Node, q *Queue) {
	// Root -> Left -> Right
	if root != nil {
		children := root.Children
		if len(children) == 0 {
			// If the root is leaf node
			q.Push(root.Val)
		} else {
			for _, child := range root.Children {
				traverse(child, q)
			}

			q.Push(root.Val)
		}
	}
}

func preorder(root *Node) []int {
	q := NewQueue()

	// DFS with preorder style
	traverse(root, q)

	// State: queue is already filled
	var output []int = make([]int, 0)
	for !q.IsEmpty() {
		front := q.Front()
		output = append(output, front)

		q.Pop()
	}

	return output
}

func postorder(root *Node) []int {
	q := NewQueue()

	// DFS with postorder style
	traversePostorder(root, q)

	// State: queue is already filled
	var output []int = make([]int, 0)
	for !q.IsEmpty() {
		front := q.Front()
		output = append(output, front)

		q.Pop()
	}

	return output
}
