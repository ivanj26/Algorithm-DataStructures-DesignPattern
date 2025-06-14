package main

import "math"

type StackInt struct {
	items []int
}

func NewStackInt() *StackInt {
	return &StackInt{
		items: make([]int, 0),
	}
}

func (this *StackInt) Push(s int) {
	this.items = append(this.items, s)
}

func (this *StackInt) IsEmpty() bool {
	return len(this.items) == 0
}

func (this *StackInt) Pop() int {
	if this.IsEmpty() {
		return math.MinInt32
	}
	top := this.items[len(this.items)-1]
	this.items = this.items[:len(this.items)-1] // remove the last element
	return top
}

func (this *StackInt) Top() int {
	if this.IsEmpty() {
		return math.MinInt32
	}

	top := this.items[len(this.items)-1]
	return top
}

func IsOperator(s string) bool {
	if len(s) == 1 {
		return s[0] == '+' || s[0] == '-' || s[0] == '/' || s[0] == '*'
	}

	return false
}

func ToInt(s string) int {
	var (
		sum  int = 0
		sign int = 1
		i    int = 0
	)

	if s[i] == '-' {
		sign = -1
		i++
	}

	for i < len(s) {
		ch := s[i]
		sum = sum*10 + (int(ch - '0'))

		i++
	}

	return sign * int(sum)
}

func evalRPN(tokens []string) int {
	if len(tokens) == 0 {
		return 0
	}

	var st *StackInt = NewStackInt()
	for _, token := range tokens {
		if IsOperator(token) {
			if st.IsEmpty() {
				continue
			}

			// Assuming there are always 2 operands in the StackInt
			operand2 := st.Pop()
			operand1 := st.Pop()

			var sum int
			switch token {
			case "-":
				sum = operand1 - operand2
				break
			case "+":
				sum = operand1 + operand2
				break
			case "/":
				sum = operand1 / operand2
				break
			case "*":
				sum = operand1 * operand2
				break
			}

			st.Push(sum)
		} else {
			st.Push(ToInt(token))
		}
	}

	// Assuming there is always 1 element at the end of loop
	return st.Top()
}
