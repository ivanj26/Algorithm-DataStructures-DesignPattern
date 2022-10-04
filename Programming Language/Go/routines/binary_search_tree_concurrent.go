package main

import (
	"fmt"
	"time"
)

type Tree struct {
	Left  *Tree
	Right *Tree
	Val   int
}

func NewTree() *Tree {
	return new(Tree)
}

func (t *Tree) GetRight() *Tree {
	return t.Right
}

func (t *Tree) GetLeft() *Tree {
	return t.Left
}

func (t *Tree) SetRight(v int) {
	t.Right = NewTree()

	t.Right.SetValue(v)
}

func (t *Tree) SetLeft(v int) {
	t.Left = NewTree()

	t.Left.SetValue(v)
}

func (t *Tree) GetValue() int {
	return t.Val
}

func (t *Tree) SetValue(v int) {
	t.Val = v
}

var Size int = 100

func main() {
	t := NewTree()
	t.SetValue(1)

	temp := t

	for i := 1; i <= Size; i++ {
		temp.SetLeft(i + 1)
		temp.SetRight(i + 2)

		temp = temp.Right
	}

	ch := make(chan bool, 1)
	target := 96

	go binSearch(t, target, ch)

	timeout := time.After(time.Second)

	select {
	case <-ch:
		fmt.Println("Found")
		return
	case <-timeout:
		fmt.Println("Timeout.")
		fmt.Printf("The value %v is not found in bintree\n", target)
		return
	}
}

func binSearch(t *Tree, target int, ch chan bool) {
	if t != nil {
		v := t.GetValue()
		if v == target {
			ch <- true
			return
		}

		fmt.Printf("Looking for target: %v but found tree->value: %v\n", target, v)

		left := t.GetLeft()
		right := t.GetRight()

		go binSearch(left, target, ch)
		go binSearch(right, target, ch)
	}
}
