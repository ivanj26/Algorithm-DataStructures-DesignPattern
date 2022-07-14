package main

type BookType int

// Represent type of book
const (
	Fictional = iota
	Science
	History
	Biology
)

// Book represent data about a book
type Book struct {
	Name    string
	Author  string
	NumPage uint
	Type    BookType
}
