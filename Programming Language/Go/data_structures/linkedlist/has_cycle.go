package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func hasCycle(head *ListNode) bool {
	s := make(map[*ListNode]bool)

	for curr := head; curr != nil; curr = curr.Next {
		if s[curr] {
			return true
		} else {
			s[curr] = true
		}
	}

	return false
}
