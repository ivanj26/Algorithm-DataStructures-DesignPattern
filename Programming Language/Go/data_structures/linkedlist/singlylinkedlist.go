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
	Pop()
	Front() int
	Count() int
	At(index int) int
	GetNthFromEnd(index int) int
	GetHead() *SinglyNode
	GetMiddle() *SinglyNode
	Print()
	Search(val int) int
	DeleteAt(index int) error
	AddList(sl2 *SinglyLinkedList) SinglyLinkedList
	Reverse()
	ReverseKGroup(k int)
	RemoveElements(val int)
	IsPalindrome() bool
	HasCycle() bool
}

type SinglyLinkedList struct {
	Head *SinglyNode
}

func NewSinglyLinkedList(head *SinglyNode) ISinglyLinkedList {
	return &SinglyLinkedList{
		Head: head,
	}
}

func (sl *SinglyLinkedList) GetHead() *SinglyNode {
	return sl.Head
}

func (sl *SinglyLinkedList) GetMiddle() *SinglyNode {
	curr := sl.Head
	middle := sl.Head

	length := 0

	for curr.Next != nil {
		length++

		if length%2 == 0 {
			middle = middle.Next
		}

		curr = curr.Next
	}

	if length%2 == 0 {
		return middle
	}

	return middle.Next
}

func (sl *SinglyLinkedList) Push(val int) {
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

func (sl *SinglyLinkedList) PushNode(node *SinglyNode) {
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

func (sl *SinglyLinkedList) Pop() {
	head := sl.Head

	if head != nil {
		var prev *SinglyNode
		prev = nil

		for curr := head; curr.Next != nil; curr = curr.Next {
			prev = curr
		}

		if prev != nil {
			// the second last node should pointing to nil
			prev.Next = nil
		} else {
			// has only one element in linkedlist
			sl.Head = nil
		}
	}
}

func (sl *SinglyLinkedList) Front() int {
	head := sl.Head

	if head != nil {
		return head.Val
	}

	return math.MinInt
}

func (sl *SinglyLinkedList) Count() int {
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

func (sl *SinglyLinkedList) At(index int) int {
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

func (sl *SinglyLinkedList) GetNthFromEnd(index int) int {
	if sl.Head == nil {
		return math.MinInt
	}

	fast := sl.Head
	slow := sl.Head
	start := 1

	for fast.Next != nil {
		fast = fast.Next
		start += 1

		if start > index {
			slow = slow.Next
		}
	}

	return slow.Val
}

func (sl *SinglyLinkedList) Print() {
	curr := sl.Head

	out := ""
	for ; curr != nil; curr = curr.Next {
		out += fmt.Sprintf("%d ", curr.Val)
	}

	fmt.Print(out)
}

func (sl *SinglyLinkedList) Search(val int) int {
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

func (sl *SinglyLinkedList) DeleteAt(index int) error {
	var (
		prev *SinglyNode
		i    int
	)

	curr := sl.Head

	if curr == nil {
		return errors.New("linkedlist is empty!")
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

	return nil
}

func (sl *SinglyLinkedList) AddList(sl2 *SinglyLinkedList) SinglyLinkedList {
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

func (sl *SinglyLinkedList) RemoveElements(val int) {
	removeRecursive(sl.Head, val)
}

func (sl *SinglyLinkedList) HasCycle() bool {
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

func (sl *SinglyLinkedList) IsPalindrome() bool {
	right := sl.Head
	return isPalindrome(&sl.Head, right)
}

func (sl *SinglyLinkedList) ReverseKGroup(k int) {
	head := sl.Head
	sn := reverseKGroup(head, k)

	sl.Head = sn
}

func (sl *SinglyLinkedList) Reverse() {
	curr := sl.Head

	if curr == nil {
		return
	}

	var (
		prev *SinglyNode
		next *SinglyNode
	)

	prev = nil
	next = nil

	for curr != nil {
		next = curr.Next

		curr.Next = prev

		prev = curr
		curr = next
	}

	sl.Head = prev
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
