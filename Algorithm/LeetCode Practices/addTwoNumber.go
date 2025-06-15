package main

type ListNode struct {
	Val  int
	Next *ListNode
}

type Stack struct {
	items []*ListNode
}

func NewStack() *Stack {
	return &Stack{
		items: make([]*ListNode, 0),
	}
}

func (this *Stack) Push(s *ListNode) {
	this.items = append(this.items, s)
}

func (this *Stack) IsEmpty() bool {
	return len(this.items) == 0
}

func (this *Stack) Pop() *ListNode {
	if this.IsEmpty() {
		return nil
	}
	top := this.items[len(this.items)-1]
	this.items = this.items[:len(this.items)-1] // remove the last element
	return top
}

func (this *Stack) Top() *ListNode {
	if this.IsEmpty() {
		return nil
	}

	top := this.items[len(this.items)-1]
	return top
}

func NewNode(val int, next *ListNode) *ListNode {
	return &ListNode{
		Val:  val,
		Next: next,
	}
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var (
		curr1           = l1
		curr2           = l2
		head3 *ListNode = nil // head of linkedlist result (l1 + l2)
		curr3 *ListNode = nil // pointing tail of head3
		carry int       = 0
	)

	st1 := NewStack()
	for curr1 != nil {
		st1.Push(curr1)
		curr1 = curr1.Next
	}

	st2 := NewStack()
	for curr2 != nil {
		st2.Push(curr2)
		curr2 = curr2.Next
	}

	for !st1.IsEmpty() && !st2.IsEmpty() {
		sum := st1.Top().Val + st2.Top().Val + carry
		st1.Pop()
		st2.Pop()

		if sum/10 > 0 {
			carry = 1
			sum -= 10
		} else {
			carry = 0
		}

		newNode := NewNode(sum, nil)
		if head3 == nil {
			head3 = newNode
			curr3 = head3
		} else {
			curr3.Next = newNode
			curr3 = curr3.Next
		}
	}

	for !st1.IsEmpty() {
		sum := st1.Top().Val + carry
		st1.Pop()

		if sum/10 > 0 {
			carry = 1
			sum -= 10
		} else {
			carry = 0
		}

		newNode := NewNode(sum, nil)
		if head3 == nil {
			head3 = newNode
			curr3 = head3
		} else {
			curr3.Next = newNode
			curr3 = curr3.Next
		}
	}

	for !st2.IsEmpty() {
		sum := st2.Top().Val + carry
		st2.Pop()

		if sum/10 > 0 {
			carry = 1
			sum -= 10
		} else {
			carry = 0
		}

		newNode := NewNode(sum, nil)
		if head3 == nil {
			head3 = newNode
			curr3 = head3
		} else {
			curr3.Next = newNode
			curr3 = curr3.Next
		}
	}

	if carry > 0 {
		curr3.Next = NewNode(carry, nil)
	}

	// Reverse the linkedlist
	curr3 = head3
	var prev *ListNode = nil
	for curr3 != nil {
		next := curr3.Next
		curr3.Next = prev

		prev = curr3
		curr3 = next
	}

	return prev
}
