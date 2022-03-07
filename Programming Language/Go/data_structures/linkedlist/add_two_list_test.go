package main

import (
	"fmt"
	"testing"
)

func TestAddTwoNumbers(t *testing.T) {
	var l1, l2 *ListNode
	l1 = &ListNode{Val: 2}
	l1.Next = &ListNode{Val: 4}
	l1.Next.Next = &ListNode{Val: 3}

	l2 = &ListNode{Val: 5}
	l2.Next = &ListNode{Val: 6}
	l2.Next.Next = &ListNode{Val: 4}

	var l3 *ListNode
	l3 = AddTwoNumbers(l1, l2)

	expectation := "7 0 8 "
	var actual string
	for l3 != nil {
		actual += fmt.Sprintf("%d ", l3.Val)
		l3 = l3.Next
	}

	if actual != expectation {
		t.Errorf("expected linkedlist: %s, actual linkedlist: %s", expectation, actual)
	}
}
