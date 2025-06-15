package main

import "math"

type Queue struct {
	items []int
}

func NewQueue() *Queue {
	return &Queue{
		items: make([]int, 0),
	}
}

func (q *Queue) Push(item int) {
	q.items = append(q.items, item)
}

func (q *Queue) IsEmpty() bool {
	return len(q.items) == 0
}

func (q *Queue) Front() int {
	if q.IsEmpty() {
		return math.MinInt32
	}
	return q.items[0]
}

func (q *Queue) Pop() {
	if q.IsEmpty() {
		return
	}
	q.items = q.items[1:]
}

func (q *Queue) Len() int {
	return len(q.items)
}

type MyStack struct {
	q *Queue
}

func NewMyStack() MyStack {
	return MyStack{
		q: NewQueue(),
	}
}

func (this *MyStack) Push(x int) {
	this.q.Push(x)
}

func (this *MyStack) Pop() int {
	if this.q.IsEmpty() {
		return math.MinInt32
	}

	size := this.q.Len() - 1
	for size > 0 {
		this.q.Push(this.q.Front())
		this.q.Pop()
		size--
	}

	front := this.q.Front()
	this.q.Pop()

	return front
}

func (this *MyStack) Top() int {
	front := this.Pop()
	this.q.Push(front)

	return front
}

func (this *MyStack) Empty() bool {
	return this.q.IsEmpty()
}
