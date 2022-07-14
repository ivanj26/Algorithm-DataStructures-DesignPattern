package main

import "fmt"

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

// Library holds collection of books
type Library struct {
	Collection []Book
}

var lib = &Library{
	Collection: []Book{
		{
			Name:    "Book 1",
			Author:  "Mr. A",
			NumPage: 50,
			Type:    Fictional,
		},

		{
			Name:    "Book 2",
			Author:  "Mr. A",
			NumPage: 50,
			Type:    Fictional,
		},

		{
			Name:    "Book 3",
			Author:  "Mr. B",
			NumPage: 50,
			Type:    Science,
		},

		{
			Name:    "Book 4",
			Author:  "Mr. B",
			NumPage: 50,
			Type:    Biology,
		},

		{
			Name:    "Book 5",
			Author:  "Mr. C",
			NumPage: 50,
			Type:    Fictional,
		},
	},
}

func (l *Library) IterateBooks(f func(Book) error) {
	for _, b := range l.Collection {
		err := f(b)
		fmt.Println()

		if err != nil {
			fmt.Println("Error encountered: ", err)
			break
		}
	}
}
