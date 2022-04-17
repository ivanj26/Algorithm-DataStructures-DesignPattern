package main

import (
	"fmt"
	"testing"
)

func Push(sl ISinglyLinkedList, val int) {
	sl.Push(val)
}

func PushNode(sl ISinglyLinkedList, val int) {
	sl.PushNode(&SinglyNode{Val: val})
}

func DeleteAt(sl ISinglyLinkedList, index int) (SinglyLinkedList, error) {
	return sl.DeleteAt(index)
}

func AddTwoNumbers(sl1 ISinglyLinkedList, sl2 SinglyLinkedList) SinglyLinkedList {
	return sl1.AddList(sl2)
}

func RemoveElements(sl ISinglyLinkedList, val int) {
	sl.RemoveElements(val)
}

func HasCycle(sl ISinglyLinkedList) bool {
	return sl.HasCycle()
}

func IsPalindrome(sl ISinglyLinkedList) bool {
	return sl.IsPalindrome()
}

func ReverseKGroup(sl ISinglyLinkedList, k int) SinglyLinkedList {
	return sl.ReverseKGroup(k)
}

// Test functions
//

func TestPush(t *testing.T) {
	t.Run("Test case 1: Test Push() function", func(t *testing.T) {
		head := &SinglyNode{
			Val: 1,
			Next: &SinglyNode{
				Val: 2,
				Next: &SinglyNode{
					Val:  3,
					Next: nil,
				},
			},
		}

		sl := SinglyLinkedList{
			Head: head,
		}

		Push(sl, 4)

		expectation := 4

		// Get last element
		var actual int
		var curr *SinglyNode
		for curr = sl.Head; curr.Next != nil; curr = curr.Next {
		}

		actual = curr.Val

		if expectation != actual {
			t.Errorf("expected value: %d, actual value: %d", expectation, actual)
		}
	})

	t.Run("Test case 2: Test PushNode() function", func(t *testing.T) {
		head := &SinglyNode{
			Val: 1,
			Next: &SinglyNode{
				Val: 2,
				Next: &SinglyNode{
					Val:  3,
					Next: nil,
				},
			},
		}

		sl := SinglyLinkedList{
			Head: head,
		}

		PushNode(sl, 4)

		expectation := 4

		// Get last element
		var actual int
		var curr *SinglyNode
		for curr = sl.Head; curr.Next != nil; curr = curr.Next {
		}

		actual = curr.Val

		if expectation != actual {
			t.Errorf("expected value: %d, actual value: %d", expectation, actual)
		}
	})
}

func TestDeleteAt(t *testing.T) {
	t.Run("Test 1: Delete first element of linkedlist", func(t *testing.T) {
		head := &SinglyNode{
			Val: 1,
			Next: &SinglyNode{
				Val: 2,
				Next: &SinglyNode{
					Val:  3,
					Next: nil,
				},
			},
		}
		sl := SinglyLinkedList{
			Head: head,
		}

		sl, err := DeleteAt(sl, 1)

		if err == nil {
			expectation := "2 3 "
			var actual string

			curr := sl.Head
			for curr != nil {
				actual += fmt.Sprintf("%d ", curr.Val)
				curr = curr.Next
			}

			if actual != expectation {
				t.Errorf("expected linkedlist: %s, actual linkedlist: %s", expectation, actual)
			}
		} else {
			t.Error("expect: error is nil")
		}
	})

	t.Run("Test 2: Delete middle element of linkedlist", func(t *testing.T) {
		head := &SinglyNode{
			Val: 1,
			Next: &SinglyNode{
				Val: 2,
				Next: &SinglyNode{
					Val:  3,
					Next: nil,
				},
			},
		}
		sl := SinglyLinkedList{
			Head: head,
		}

		sl, err := DeleteAt(sl, 2)

		if err == nil {
			expectation := "1 3 "
			var actual string

			curr := sl.Head
			for curr != nil {
				actual += fmt.Sprintf("%d ", curr.Val)
				curr = curr.Next
			}

			if actual != expectation {
				t.Errorf("expected linkedlist: %s, actual linkedlist: %s", expectation, actual)
			}
		} else {
			t.Error("expect: error is nil")
		}
	})

	t.Run("Test 3: Try to delete empty linkedlist", func(t *testing.T) {
		sl := SinglyLinkedList{
			Head: nil,
		}

		sl, err := DeleteAt(sl, 2)

		if err == nil {
			t.Error("expect: error occured")
		}
	})
}

func TestAddTwoNumbers(t *testing.T) {
	var l1, l2 *SinglyNode
	l1 = &SinglyNode{Val: 2}
	l1.Next = &SinglyNode{Val: 4}
	l1.Next.Next = &SinglyNode{Val: 3}

	l2 = &SinglyNode{Val: 5}
	l2.Next = &SinglyNode{Val: 6}
	l2.Next.Next = &SinglyNode{Val: 4}

	sl1 := SinglyLinkedList{
		Head: l1,
	}
	sl2 := SinglyLinkedList{
		Head: l2,
	}

	sl3 := AddTwoNumbers(sl1, sl2)
	l3 := sl3.Head

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

func TestRemoveElements(t *testing.T) {
	node := &SinglyNode{
		Val: 3,
		Next: &SinglyNode{
			Val: 4,
			Next: &SinglyNode{
				Val: 6,
				Next: &SinglyNode{
					Val:  5,
					Next: nil,
				},
			},
		},
	}
	expectNode := &SinglyNode{
		Val: 3,
		Next: &SinglyNode{
			Val: 4,
			Next: &SinglyNode{
				Val:  6,
				Next: nil,
			},
		},
	}

	// Test 1
	t.Run("Test case 1: If given element is not included in singlylinkedlist. Expect: nothing is removed", func(t *testing.T) {
		sl := SinglyLinkedList{Head: node}
		RemoveElements(sl, 5)

		curr1 := sl.Head
		curr2 := expectNode
		for curr1 != nil && curr2 != nil {
			if curr1.Val != curr2.Val {
				t.Errorf("expected: %d, actual: %d", curr2.Val, curr1.Val)
			}

			curr1 = curr1.Next
			curr2 = curr2.Next
		}
	})

	// Test 2
	t.Run("Test case 2: If given element is included in singlylinkedlist. Expect: element: 4 is removed from sl", func(t *testing.T) {
		sl := SinglyLinkedList{Head: node}
		RemoveElements(sl, 4)

		expectNode = &SinglyNode{
			Val: 3,
			Next: &SinglyNode{
				Val:  6,
				Next: nil,
			},
		}

		curr1 := sl.Head
		curr2 := expectNode
		for curr1 != nil && curr2 != nil {
			if curr1.Val != curr2.Val {
				t.Errorf("expected: %d, actual: %d", curr2.Val, curr1.Val)
			}

			curr1 = curr1.Next
			curr2 = curr2.Next
		}
	})
}

func TestHasCycle(t *testing.T) {
	t.Run("Test case 1: If do not have any cycle", func(t *testing.T) {
		head := &SinglyNode{
			Val: 4,
			Next: &SinglyNode{
				Val: 5,
				Next: &SinglyNode{
					Val:  6,
					Next: nil,
				},
			},
		}

		sl := SinglyLinkedList{Head: head}
		actual := HasCycle(sl)

		if expectation := false; expectation != actual {
			t.Errorf("expected isCyclic: %t, actual isCyclic: %t", expectation, actual)
		}
	})

	t.Run("Test case 2: If have cycle inside", func(t *testing.T) {
		n6 := &SinglyNode{Val: 60}
		n5 := &SinglyNode{Val: 50, Next: n6}
		n4 := &SinglyNode{Val: 40, Next: n5}
		n3 := &SinglyNode{Val: 30, Next: n4}
		n6.Next = n3

		sl := SinglyLinkedList{Head: n3}
		actual := HasCycle(sl)

		if expectation := true; expectation != actual {
			t.Errorf("expected isCyclic: %t, actual isCyclic: %t", expectation, actual)
		}
	})
}

func TestIsPalindrome(t *testing.T) {
	t.Run("Test 1: Palindrome linkedlist", func(t *testing.T) {
		head := &SinglyNode{
			Val: 1,
			Next: &SinglyNode{
				Val: 2,
				Next: &SinglyNode{
					Val:  1,
					Next: nil,
				},
			},
		}

		sl := SinglyLinkedList{
			Head: head,
		}
		actual := IsPalindrome(sl)

		expectation := true
		if expectation != actual {
			t.Error("expect: actual value should be true!")
		}
	})

	t.Run("Test 2: Non-palindrome linkedlist", func(t *testing.T) {
		head := &SinglyNode{
			Val: 1,
			Next: &SinglyNode{
				Val:  2,
				Next: nil,
			},
		}

		sl := SinglyLinkedList{
			Head: head,
		}
		actual := IsPalindrome(sl)

		expectation := false
		if expectation != actual {
			t.Error("expect: actual value should be false!")
		}
	})
}

func TestReverseKGroup(t *testing.T) {
	head := &SinglyNode{
		Val: 3,
		Next: &SinglyNode{
			Val: 4,
			Next: &SinglyNode{
				Val:  6,
				Next: nil,
			},
		},
	}
	expectation := "4 3 6 "

	sl := SinglyLinkedList{Head: head}
	reversed := ReverseKGroup(sl, 2)
	var actual string

	for curr := reversed.Head; curr != nil; curr = curr.Next {
		actual += fmt.Sprintf("%d ", curr.Val)
	}

	if actual != expectation {
		t.Errorf("expected linkedlist: %s, actual linkedlist: %s", expectation, actual)
	}
}
