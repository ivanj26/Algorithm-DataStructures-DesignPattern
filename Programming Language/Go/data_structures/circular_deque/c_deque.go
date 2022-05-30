package main

type CircularDeque struct {
	MaxSize int
	Elmt    []int
}

func NewCircularDeque(k int) *CircularDeque {
	return &CircularDeque{
		Elmt:    make([]int, 0),
		MaxSize: k,
	}
}

func (this *CircularDeque) InsertFront(k int) bool {
	if !this.IsFull() {
		this.Elmt = append(this.Elmt, 0)

		copy(this.Elmt[1:], this.Elmt)

		this.Elmt[0] = k
		return true
	}

	return false
}

func (this *CircularDeque) InsertLast(k int) bool {
	if !this.IsFull() {
		this.Elmt = append(this.Elmt, k)

		return true
	}

	return false
}

func (this *CircularDeque) DeleteFront() bool {
	if !this.IsEmpty() {
		this.Elmt = this.Elmt[1:]

		return true
	}

	return false
}

func (this *CircularDeque) DeleteLast() bool {
	if !this.IsEmpty() {
		length := len(this.Elmt)
		this.Elmt = this.Elmt[:length-1]

		return true
	}

	return false
}

func (this *CircularDeque) GetFront() int {
	if !this.IsEmpty() {
		return this.Elmt[0]
	}

	return -1
}

func (this *CircularDeque) GetRear() int {
	if !this.IsEmpty() {
		return this.Elmt[len(this.Elmt)-1]
	}

	return -1
}

func (this *CircularDeque) IsEmpty() bool {
	return len(this.Elmt) == 0
}

func (this *CircularDeque) IsFull() bool {
	return len(this.Elmt) == this.MaxSize
}
