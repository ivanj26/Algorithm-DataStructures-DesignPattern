package main

import (
	"fmt"
	"testing"
)

func TestReverseKGroup(t *testing.T) {
	head := &ListNode{
		Val: 3,
		Next: &ListNode{
			Val: 4,
			Next: &ListNode{
				Val:  6,
				Next: nil,
			},
		},
	}
	expectation := "4 3 6 "

	reversed := reverseKGroup(head, 2)
	var actual string

	for curr := reversed; curr != nil; curr = curr.Next {
		actual += fmt.Sprintf("%d ", curr.Val)
	}

	if actual != expectation {
		t.Errorf("expected linkedlist: %s, actual linkedlist: %s", expectation, actual)
	}
}
