package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func AddTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	l3 := &ListNode{}
	curr := l3
	carry := 0

	for l1 != nil || l2 != nil {
		sum := carry

		if l1 != nil {
			sum += l1.Val
			l1 = l1.Next
		}

		if l2 != nil {
			sum += l2.Val
			l2 = l2.Next
		}

		carry = sum / 10
		sum = sum % 10

		curr.Next = &ListNode{Val: sum}
		curr = curr.Next
	}

	// Handle if carry is remain
	if carry > 0 {
		curr.Next = &ListNode{Val: carry}
	}

	return l3.Next
}
