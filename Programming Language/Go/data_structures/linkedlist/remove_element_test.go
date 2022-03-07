package main

import (
	"testing"
)

func TestRemoveElements(t *testing.T) {
	node := &ListNode{
		Val: 3,
		Next: &ListNode{
			Val: 4,
			Next: &ListNode{
				Val: 6,
				Next: &ListNode{
					Val:  5,
					Next: nil,
				},
			},
		},
	}
	expectNode := &ListNode{
		Val: 3,
		Next: &ListNode{
			Val: 4,
			Next: &ListNode{
				Val:  6,
				Next: nil,
			},
		},
	}

	removed := removeElements(node, 5)

	curr1 := removed
	curr2 := expectNode
	for curr1 != nil && curr2 != nil {
		if curr1.Val != curr2.Val {
			t.Errorf("expected: %d, actual: %d", curr2.Val, curr1.Val)
		}

		curr1 = curr1.Next
		curr2 = curr2.Next
	}
}
