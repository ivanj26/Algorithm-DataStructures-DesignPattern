package main

type MyCircularQueue struct {
	Elmt    []int
	MaxSize int
}

func Constructor(k int) MyCircularQueue {
	return MyCircularQueue{
		Elmt:    make([]int, 0, k),
		MaxSize: k,
	}
}

func (this *MyCircularQueue) EnQueue(value int) bool {
	if !this.IsFull() {
		this.Elmt = append(this.Elmt, value)
		return true
	}

	return false
}

func (this *MyCircularQueue) DeQueue() bool {
	if !this.IsEmpty() {
		this.Elmt = this.Elmt[1:]

		return true
	}

	return false
}

func (this *MyCircularQueue) Front() int {
	if !this.IsEmpty() {
		return this.Elmt[0]
	}

	return -1
}

func (this *MyCircularQueue) Rear() int {
	if !this.IsEmpty() {
		return this.Elmt[len(this.Elmt)-1]
	}

	return -1
}

func (this *MyCircularQueue) IsEmpty() bool {
	return len(this.Elmt) == 0
}

func (this *MyCircularQueue) IsFull() bool {
	return len(this.Elmt) == this.MaxSize
}
