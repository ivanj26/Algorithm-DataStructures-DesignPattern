package main

type ListNode struct {
	Next *ListNode
	Val  int
}

type Stack struct {
	items []*ListNode
}

func NewStack() *Stack {
	return &Stack{
		items: make([]*ListNode, 0),
	}
}

func (s *Stack) Push(node *ListNode) {
	s.items = append(s.items, node)
}

func (s *Stack) IsEmpty() bool {
	return len(s.items) == 0
}

func (s *Stack) Pop() {
	if s.IsEmpty() {
		return
	}

	s.items = s.items[:len(s.items)-1]
}

func (s *Stack) Top() *ListNode {
	if s.IsEmpty() {
		return nil
	}

	return s.items[len(s.items)-1]
}

func length(node *ListNode) int {
	if node == nil {
		return 0
	}

	return 1 + length(node.Next)
}

func (s *Stack) IsPalindrome() bool {
	i := 0
	j := len(s.items) - 1

	for i <= j {
		if s.items[i].Val != s.items[j].Val {
			return false
		}

		i++
		j--
	}

	return true
}

func isPalindrome(head *ListNode) bool {
	var llen int = length(head)
	if llen == 1 {
		return true
	}

	st := NewStack()
	curr := head
	for i := 1; i <= llen; i++ {
		st.Push(curr)
		curr = curr.Next
	}

	return st.IsPalindrome()
}
