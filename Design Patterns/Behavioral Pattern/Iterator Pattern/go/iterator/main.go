package main

import "fmt"

func main() {
	collection := []Book{
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
	}

	container := NewBookContainer(collection)
	iter := container.GetIterator()

	for iter.HasNext() {
		b := iter.Next()

		fmt.Println("Book Name: ", b.Name)
		fmt.Println("Book Author: ", b.Author)
		fmt.Println("Number of Page: ", b.NumPage)
		fmt.Println("Book Type: ", b.Type)
		fmt.Println()
	}
}
