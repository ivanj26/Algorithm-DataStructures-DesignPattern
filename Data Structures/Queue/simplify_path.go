package main

import "strings"

const (
	CURRENT_FOLDER = "."
	PARENT_FOLDER  = ".."
)

type Deque struct {
	items []string
}

func NewDeque() *Deque {
	return &Deque{
		items: make([]string, 0),
	}
}

func (dq *Deque) IsEmpty() bool {
	return len(dq.items) == 0
}

func (dq *Deque) PushBack(s string) {
	dq.items = append(dq.items, s)
}

func (dq *Deque) PopBack() {
	if dq.IsEmpty() {
		return
	}

	dq.items = dq.items[:len(dq.items)-1]
}

func (dq *Deque) PopFront() {
	if dq.IsEmpty() {
		return
	}

	dq.items = dq.items[1:]
}

func (dq *Deque) Front() string {
	if dq.IsEmpty() {
		return ""
	}

	return dq.items[0]
}

func reconstructString(dq *Deque) string {
	var result strings.Builder
	result.WriteString("/")

	for !dq.IsEmpty() {
		front := dq.Front()
		dq.PopFront()

		if result.Len() == 1 {
			result.WriteString(front)
		} else {
			result.WriteString("/" + front)
		}
	}

	return result.String()
}

func insertToDeque(dq *Deque, folder string) {
	if len(folder) == 0 || (len(folder) == 1 && folder == CURRENT_FOLDER) {
		// skip, do nothing
	} else if folder == PARENT_FOLDER {
		if !dq.IsEmpty() {
			dq.PopBack()
		}
	} else {
		dq.PushBack(folder)
	}
}

func simplifyPath(path string) string {
	dq := NewDeque()
	delim := "/"

	parts := strings.Split(path, delim)
	for _, part := range parts {
		insertToDeque(dq, part)
	}

	return reconstructString(dq)
}
