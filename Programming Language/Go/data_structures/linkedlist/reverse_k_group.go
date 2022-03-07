package main

type ListNode struct {
	Next *ListNode
	Val  int
}

func length(head *ListNode) int {
	if head == nil {
		return 0
	}

	return 1 + length(head.Next)
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil {
		return nil
	}

	if length(head) < k {
		return head
	}

	var prev *ListNode
	prev = nil
	curr := head

	for i := 0; i < k && curr != nil; i++ {
		next := curr.Next
		curr.Next = prev

		prev = curr
		curr = next
	}

	head.Next = reverseKGroup(curr, k)
	return prev
}
