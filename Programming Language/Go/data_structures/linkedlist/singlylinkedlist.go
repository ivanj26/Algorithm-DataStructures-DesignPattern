package main

import (
	"errors"
	"fmt"
	"math"
)

type SinglyNode struct {
	Next *SinglyNode
	Val  int
}

type ISinglyLinkedList interface {
	Push(val int)
	PushNode(node *SinglyNode)
	Count() int
	At(index int) int
	Print() string
	Search(val int) int
	DeleteAt(index int) (SinglyLinkedList, error)
	AddList(sl2 SinglyLinkedList) SinglyLinkedList
	ReverseKGroup(k int) SinglyLinkedList
	RemoveElements(val int)
	IsPalindrome() bool
	HasCycle() bool
}

type SinglyLinkedList struct {
	Head *SinglyNode
}

func (sl SinglyLinkedList) Push(val int) {
	head := sl.Head

	if head == nil {
		head = &SinglyNode{
			Val: val,
		}

		return
	}

	var curr *SinglyNode
	node := &SinglyNode{Val: val}

	for curr = head; curr.Next != nil; curr = curr.Next {
		//
	}

	curr.Next = node
}

func (sl SinglyLinkedList) PushNode(node *SinglyNode) {
	head := sl.Head

	if head == nil {
		head = node
		return
	}

	var curr *SinglyNode

	for curr = sl.Head; curr.Next != nil; curr = curr.Next {

	}

	curr.Next = node
}

func (sl SinglyLinkedList) Count() int {
	if sl.Head == nil {
		return 0
	}

	var (
		curr  *SinglyNode
		count int
	)

	count = 0
	for curr = sl.Head; curr != nil; curr = curr.Next {
		count++
	}

	return count
}

func (sl SinglyLinkedList) At(index int) int {
	curr := sl.Head

	var i int

	for i = 0; i < index && curr != nil; i++ {
		curr = curr.Next
	}

	if i == index {
		if curr != nil {
			return curr.Val
		}

		return math.MinInt
	}

	return math.MinInt
}

func (sl SinglyLinkedList) Print() string {
	curr := sl.Head

	out := ""
	for ; curr != nil; curr = curr.Next {
		out += fmt.Sprintf("%d ", curr.Val)
	}

	return out
}

func (sl SinglyLinkedList) Search(val int) int {
	curr := sl.Head
	if curr == nil {
		return -1
	}

	for i := 0; curr != nil; curr = curr.Next {
		if curr.Val == val {
			return i
		}

		i++
	}

	return -1
}

func (sl SinglyLinkedList) DeleteAt(index int) (SinglyLinkedList, error) {
	var (
		prev *SinglyNode
		i    int
	)

	curr := sl.Head

	if curr == nil {
		return sl, errors.New("linkedlist is empty!")
	}

	prev = nil
	for i = 1; curr != nil && i < index; i++ {
		prev = curr
		curr = curr.Next
	}

	if i == index {
		if prev == nil {
			sl.Head = curr.Next
		} else {
			prev.Next = curr.Next
		}
	}

	return sl, nil
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

func (sl SinglyLinkedList) IsPalindrome() bool {
	right := sl.Head
	return isPalindrome(&sl.Head, right)
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

func isPalindrome(left **SinglyNode, right *SinglyNode) bool {
	if right == nil {
		return true
	}

	isp := isPalindrome(left, right.Next)
	if isp == false {
		return false
	}

	result := (*left).Val == right.Val
	(*left) = (*left).Next

	return result
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
