package main

import (
	"fmt"
	"math"
)

type Item struct {
	val           int
	globalMinimum int
}

// Basic idea:
// 1. Stack simpan sebuah item dengan prop: val dan global minimum.

// st<Item> = {Item(-2, -2), Item(0, -2)}
// st.Push(-2)
// st.Push(0)
// st.Push(3)
// st.GetMin() = Peek top element (Item), lookup globalMinimum prop.

// 2. Operation is Push() -> insert the item into stack, compare previous minimum dengan value with current value
// 3. Operation is Pop() -> remove last/top element. (Only applicable if the stack is not empty)
// 4. Operation is Top() -> lookup last/top element. (Only applicable if the stack is not empty)
// 5. Operation is GetMinimum() -> lookup last/top element. return the item.globalMinimum (Only applicable if the stack is not empty)

type MinStack struct {
	items []Item
}

func Constructor() MinStack {
	return MinStack{
		items: make([]Item, 0),
	}
}

func (this *MinStack) IsEmpty() bool {
	return len(this.items) == 0
}

func (this *MinStack) Push(val int) {
	if this.IsEmpty() {
		this.items = append(this.items, Item{val: val, globalMinimum: val})
		return
	}

	top := this.items[len(this.items)-1]
	var minimum int = top.globalMinimum
	if minimum > val {
		minimum = val
	}

	this.items = append(this.items, Item{val: val, globalMinimum: minimum})
}

func (this *MinStack) Pop() {
	if this.IsEmpty() {
		return
	}

	this.items = this.items[:len(this.items)-1]
}

func (this *MinStack) Top() int {
	if this.IsEmpty() {
		return -1
	}

	return this.items[len(this.items)-1].val
}

func (this *MinStack) GetMin() int {
	if this.IsEmpty() {
		return math.MinInt32
	}

	return this.items[len(this.items)-1].globalMinimum
}

func main() {
	minStack := Constructor()
	minStack.Push(-2)
	minStack.Push(0)
	minStack.Push(-3)
	fmt.Println(minStack.GetMin()) // return -3

	minStack.Pop()
	fmt.Println(minStack.Top())    // return 0
	fmt.Println(minStack.GetMin()) // return -2
}
