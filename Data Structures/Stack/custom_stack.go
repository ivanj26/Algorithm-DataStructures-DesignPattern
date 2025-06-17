package main

type CustomStack struct {
	items    []int
	capacity int
}

func NewCustomStack(maxSize int) CustomStack {
	return CustomStack{
		items:    make([]int, 0),
		capacity: maxSize,
	}
}

func (this *CustomStack) Push(x int) {
	if this.capacity <= len(this.items) {
		return // do not push any new element as the capacity reached max
	}

	this.items = append(this.items, x)
}

func (this *CustomStack) IsEmpty() bool {
	return len(this.items) == 0
}

func (this *CustomStack) Pop() int {
	if !this.IsEmpty() {
		topIdx := len(this.items) - 1
		top := this.items[topIdx]

		this.items = this.items[:len(this.items)-1]

		return top
	}

	return -1
}

func min(i, j int) int {
	if i < j {
		return i
	}

	return j
}

func (this *CustomStack) Increment(k int, val int) {
	if this.IsEmpty() {
		return
	}

	minimum := min(k, len(this.items))
	start := 0

	for start < minimum {
		this.items[start] += val
		start++
	}
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * obj := Constructor(maxSize);
 * obj.Push(x);
 * param_2 := obj.Pop();
 * obj.Increment(k,val);
 */
