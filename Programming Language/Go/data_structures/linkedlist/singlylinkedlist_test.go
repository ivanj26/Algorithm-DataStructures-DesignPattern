package main

import (
	"fmt"
	"io/ioutil"
	"math"
	"os"
	"testing"
)

// Test functions
//

func TestReverse(t *testing.T) {
	t.Run("Test 1: reverse empty linkedlist", func(t *testing.T) {
		sl := NewSinglyLinkedList(nil)

		sl.Reverse()
		// expect no error occurs
	})

	t.Run("Test 2: reverse non-empty linkedlist", func(t *testing.T) {
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
		sl := NewSinglyLinkedList(head)
		sl.Reverse()

		var actual string
		for curr := sl.GetHead(); curr != nil; curr = curr.Next {
			actual += fmt.Sprintf("%d ", curr.Val)
		}

		if expectation := "3 2 1 "; expectation != actual {
			t.Errorf("expectation: %s, actual: %s", expectation, actual)
		}
	})
}

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

		sl := NewSinglyLinkedList(head)
		sl.Push(4)

		expectation := 4

		// Get last element
		var actual int
		var curr *SinglyNode
		for curr = sl.GetHead(); curr.Next != nil; curr = curr.Next {
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

		sl := NewSinglyLinkedList(head)
		node := new(SinglyNode)
		node.Val = 4

		sl.PushNode(node)

		expectation := 4

		// Get last element
		var actual int
		var curr *SinglyNode
		for curr = sl.GetHead(); curr.Next != nil; curr = curr.Next {
		}

		actual = curr.Val

		if expectation != actual {
			t.Errorf("expected value: %d, actual value: %d", expectation, actual)
		}
	})
}

func TestPop(t *testing.T) {
	t.Run("Test case 1: if linkedlist is empty, expect no error occurs", func(t *testing.T) {
		sl := NewSinglyLinkedList(nil)
		sl.Pop()
	})

	t.Run("Test case 2: if linkedlist has more than 1 element", func(t *testing.T) {
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
		sl := NewSinglyLinkedList(head)
		sl.Pop()

		expected := []int{1, 2}
		expectedLength := len(expected)
		i := 0

		if expectedLength != sl.Count() {
			t.Errorf("Failed because linkedlist length should be %d", expectedLength)
		}

		for curr := sl.GetHead(); curr.Next != nil; curr = curr.Next {
			expectation := expected[i]
			actual := curr.Val

			if actual != expectation {
				t.Errorf("expected value: %d, actual value: %d", expectation, actual)
			}

			i += 1
		}
	})

	t.Run("Test case 3: if linkedlist only has 1 element", func(t *testing.T) {
		head := &SinglyNode{
			Val:  1,
			Next: nil,
		}
		sl := NewSinglyLinkedList(head)
		sl.Pop()

		expected := []int{}
		expectedLength := len(expected)

		if expectedLength != sl.Count() {
			t.Errorf("Failed because linkedlist length should be %d", expectedLength)
		}
	})
}

func TestFront(t *testing.T) {
	t.Run("Test case 1: if linkedlist is empty, expect the value is math.MinInt", func(t *testing.T) {
		sl := NewSinglyLinkedList(nil)

		actual := sl.Front()

		if expected := math.MinInt; actual != expected {
			t.Errorf("expected value: %d, actual value: %d", expected, actual)
		}
	})

	t.Run("Test case 2: if linkedlist is not empty, expect return the value of head pointer", func(t *testing.T) {
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
		sl := NewSinglyLinkedList(head)

		actual := sl.Front()

		if expected := 1; actual != expected {
			t.Errorf("expected value: %d, actual value: %d", expected, actual)
		}

		// do Pop() method
		sl.Pop()
		sl.Pop()
		sl.Pop()

		actual = sl.Front()

		if expected := math.MinInt; actual != expected {
			t.Errorf("expected value: %d, actual value: %d", expected, actual)
		}
	})
}

func TestCount(t *testing.T) {
	t.Run("Test 1 : empty linkedlist", func(t *testing.T) {
		sl := NewSinglyLinkedList(nil)
		actual := sl.Count()

		if expectation := 0; expectation != actual {
			t.Errorf("expectation: %d, actual: %d", expectation, actual)
		}
	})

	t.Run("Test 2 : non-empty linkedlist", func(t *testing.T) {
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

		sl := NewSinglyLinkedList(head)
		actual := sl.Count()

		if expectation := 3; expectation != actual {
			t.Errorf("expectation: %d, actual: %d", expectation, actual)
		}
	})
}

func TestSearch(t *testing.T) {
	t.Run("Test 1 : empty linkedlist", func(t *testing.T) {
		sl := NewSinglyLinkedList(nil)
		actual := sl.Search(1)

		if expectation := -1; expectation != actual {
			t.Errorf("expectation: %d, actual: %d", expectation, actual)
		}
	})

	t.Run("Test 2 : non-empty linkedlist", func(t *testing.T) {
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

		sl := NewSinglyLinkedList(head)
		actual := sl.Search(2)

		if expectation := 1; expectation != actual {
			t.Errorf("expectation: %d, actual: %d", expectation, actual)
		}
	})
}

func TestAt(t *testing.T) {
	t.Run("Test 1: empty linkedlist", func(t *testing.T) {
		sl := NewSinglyLinkedList(nil)

		actual := sl.At(2)
		if expectation := math.MinInt; expectation != actual {
			t.Errorf("expectation: %d, actual: %d", expectation, actual)
		}
	})

	t.Run("Test 2: non-empty linkedlist", func(t *testing.T) {
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
		sl := NewSinglyLinkedList(head)

		actual := sl.At(2)
		if expectation := 3; expectation != actual {
			t.Errorf("expectation: %d, actual: %d", expectation, actual)
		}
	})
}

func TestGetNthFromEnd(t *testing.T) {
	t.Run(
		"Test Case 1\n"+
			" Given that linkedlist 1->2->3\n"+
			" we want to get last element\n"+
			" expect return 3",
		func(t *testing.T) {
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

			sl := NewSinglyLinkedList(head)

			actual := sl.GetNthFromEnd(1)

			if expectation := 3; actual != expectation {
				t.Errorf("expectation: %d, actual: %d", expectation, actual)
			}
		},
	)

	t.Run(
		"Test Case 2\n"+
			" Given that empty linkedlist\n"+
			" we want to get last element\n"+
			" expect return math.MinInt",
		func(t *testing.T) {
			sl := NewSinglyLinkedList(nil)

			actual := sl.GetNthFromEnd(1)

			if expectation := math.MinInt; actual != expectation {
				t.Errorf("expectation: %d, actual: %d", expectation, actual)
			}
		},
	)
}

func TestPrint(t *testing.T) {
	t.Run("Test: empty linkedlist", func(t *testing.T) {
		sl := NewSinglyLinkedList(nil)

		rescueStdout := os.Stdout
		r, w, _ := os.Pipe()
		os.Stdout = w

		sl.Print()

		w.Close()
		out, _ := ioutil.ReadAll(r)
		os.Stdout = rescueStdout

		actual := fmt.Sprintf("%s", out)

		if expectation := ""; expectation != actual {
			t.Errorf("expectation: %s, actual: %s", expectation, actual)
		}
	})

	t.Run("Test: non-empty linkedlist", func(t *testing.T) {
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
		sl := NewSinglyLinkedList(head)

		rescueStdout := os.Stdout
		r, w, _ := os.Pipe()
		os.Stdout = w

		sl.Print()

		w.Close()
		out, _ := ioutil.ReadAll(r)
		os.Stdout = rescueStdout

		actual := fmt.Sprintf("%s", out)

		if expectation := "1 2 3 "; expectation != actual {
			t.Errorf("expectation: %s, actual: %s", expectation, actual)
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
		sl := NewSinglyLinkedList(head)

		err := sl.DeleteAt(1)

		if err == nil {
			expectation := "2 3 "
			var actual string

			curr := sl.GetHead()
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
		sl := NewSinglyLinkedList(head)

		err := sl.DeleteAt(2)

		if err == nil {
			expectation := "1 3 "
			var actual string

			curr := sl.GetHead()
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
		sl := NewSinglyLinkedList(nil)

		err := sl.DeleteAt(2)

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

	sl1 := NewSinglyLinkedList(l1)
	sl2 := &SinglyLinkedList{Head: l2}

	sl3 := sl1.AddList(sl2)
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
		sl := NewSinglyLinkedList(node)
		sl.RemoveElements(5)

		curr1 := sl.GetHead()
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
		sl := NewSinglyLinkedList(node)
		sl.RemoveElements(4)

		expectNode = &SinglyNode{
			Val: 3,
			Next: &SinglyNode{
				Val:  6,
				Next: nil,
			},
		}

		curr1 := sl.GetHead()
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

		sl := NewSinglyLinkedList(head)
		actual := sl.HasCycle()

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

		sl := NewSinglyLinkedList(n3)
		actual := sl.HasCycle()

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

		sl := NewSinglyLinkedList(head)
		actual := sl.IsPalindrome()

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

		sl := NewSinglyLinkedList(head)
		actual := sl.IsPalindrome()

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

	sl := NewSinglyLinkedList(head)
	sl.ReverseKGroup(2)
	var actual string

	for curr := sl.GetHead(); curr != nil; curr = curr.Next {
		actual += fmt.Sprintf("%d ", curr.Val)
	}

	if actual != expectation {
		t.Errorf("expected linkedlist: %s, actual linkedlist: %s", expectation, actual)
	}
}
