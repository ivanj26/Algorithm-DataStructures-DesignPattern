package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeRecursive(head *ListNode, val int) *ListNode {
	if head == nil {
		return head
	}

	next := head.Next
	head.Next = removeRecursive(next, val)

	if head.Val == val {
		n := head.Next

		return n
	}

	return head
}

func removeElements(head *ListNode, val int) *ListNode {
	return removeRecursive(head, val)
}
