package main

import (
	"testing"
)

func TestHasCycle(t *testing.T) {
	t.Run("Test case 1: If do not have any cycle", func(t *testing.T) {
		head := &ListNode{
			Val: 4,
			Next: &ListNode{
				Val: 5,
				Next: &ListNode{
					Val:  6,
					Next: nil,
				},
			},
		}

		actual := hasCycle(head)

		if expectation := false; expectation != actual {
			t.Errorf("expected isCyclic: %t, actual isCyclic: %t", expectation, actual)
		}
	})

	t.Run("Test case 2: If have cycle inside", func(t *testing.T) {
		n6 := &ListNode{Val: 60}
		n5 := &ListNode{Val: 50, Next: n6}
		n4 := &ListNode{Val: 40, Next: n5}
		n3 := &ListNode{Val: 30, Next: n4}
		n6.Next = n3

		actual := hasCycle(n3)

		if expectation := true; expectation != actual {
			t.Errorf("expected isCyclic: %t, actual isCyclic: %t", expectation, actual)
		}
	})
}
