package main

type SinglyNode struct {
	Next *SinglyNode
	Val  int
}

type ISinglyLinkedList interface {
	AddList(sl2 SinglyLinkedList) SinglyLinkedList
	ReverseKGroup(k int) SinglyLinkedList
	RemoveElements(val int)
	HasCycle() bool
}

type SinglyLinkedList struct {
	Head *SinglyNode
}

func (sl SinglyLinkedList) AddList(sl2 SinglyLinkedList) SinglyLinkedList {
	l1 := sl.Head
	l2 := sl2.Head
	l3 := &SinglyNode{}
	curr := l3
	carry := 0

	for l1 != nil || l2 != nil {
		sum := carry

		if nil != l1 {
			sum += l1.Val
			l1 = l1.Next
		}

		if nil != l2 {
			sum += l2.Val
			l2 = l2.Next
		}

		carry = sum / 10
		sum = sum % 10

		curr.Next = &SinglyNode{Val: sum}
		curr = curr.Next
	}

	// Handle if carry is remain
	if carry > 0 {
		curr.Next = &SinglyNode{Val: carry}
	}

	return SinglyLinkedList{
		Head: l3.Next,
	}
}

func (sl SinglyLinkedList) RemoveElements(val int) {
	removeRecursive(sl.Head, val)
}

func (sl SinglyLinkedList) HasCycle() bool {
	s := make(map[*SinglyNode]bool)

	for curr := sl.Head; curr != nil; curr = curr.Next {
		if s[curr] {
			return true
		} else {
			s[curr] = true
		}
	}

	return false
}

func (sl SinglyLinkedList) ReverseKGroup(k int) SinglyLinkedList {
	head := sl.Head
	sn := reverseKGroup(head, k)

	return SinglyLinkedList{Head: sn}
}

// ...Util function
func length(head *SinglyNode) int {
	if head == nil {
		return 0
	}

	return 1 + length(head.Next)
}

func reverseKGroup(head *SinglyNode, k int) *SinglyNode {
	if head == nil {
		return nil
	}

	if length(head) < k {
		return head
	}

	var prev *SinglyNode
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

func removeRecursive(head *SinglyNode, val int) *SinglyNode {
	if head == nil {
		return head
	}

	next := head.Next
	head.Next = removeRecursive(next, val)

	if head.Val == val {
		n := head.Next

		return n
	}

	return head
}
