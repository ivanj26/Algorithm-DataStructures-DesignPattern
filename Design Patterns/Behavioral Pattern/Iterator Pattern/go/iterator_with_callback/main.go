package main

import "fmt"

func main() {
	lib.IterateBooks(func(b Book) error {
		fmt.Println("Book Name: ", b.Name)
		fmt.Println("Book Author: ", b.Author)
		fmt.Println("Number of Page: ", b.NumPage)

		return nil
	})
}
