package main

type stack struct {
	items []rune
}

func (s *stack) IsEmpty() bool {
	return len(s.items) == 0
}

func (s *stack) Push(ch rune) {
	s.items = append(s.items, ch)
}

func (s *stack) Pop() (rune, bool) {
	if len(s.items) == 0 {
		var emptyRune rune
		return emptyRune, false
	}

	top := s.items[len(s.items)-1]
	s.items = s.items[:len(s.items)-1]

	return top, true
}

func (s *stack) Top() rune {
	if len(s.items) == 0 {
		var emptyRune rune
		return emptyRune
	}

	return s.items[len(s.items)-1]
}

func isValid(s string) bool {
	var st *stack = &stack{
		items: []rune{},
	}

	for _, ch := range s {
		switch ch {
		case '(':
			st.Push(ch)
			break
		case '[':
			st.Push(ch)
			break
		case '{':
			st.Push(ch)
			break
		case '}':
			if st.IsEmpty() {
				return false
			}

			if top := st.Top(); top != '{' {
				return false
			}

			st.Pop()
			break
		case ']':
			if st.IsEmpty() {
				return false
			}

			if top := st.Top(); top != '[' {
				return false
			}

			st.Pop()
			break
		case ')':
			if st.IsEmpty() {
				return false
			}

			if top := st.Top(); top != '(' {
				return false
			}

			st.Pop()
			break
		}
	}

	return st.IsEmpty() // If the stack is empty, the parentheses is valid
}
