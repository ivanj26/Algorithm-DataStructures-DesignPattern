package main

import (
	"fmt"
)

func main() {
	// for loop basic
	for i := 1; i <= 10; i++ {
		fmt.Println(i)
	}

	// with break
	for i := 1; i <= 10; i++ {
		if i > 5 {
			fmt.Println()
			break
		}
		fmt.Printf("%d ", i)
	}

	fmt.Println("Line after break...")

	// with continue, let's print odd numbers
	fmt.Println("\n\nPrinting the odd numbers from 1 to 10:")
	for i := 1; i <= 10; i++ {
		if i%2 == 0 {
			continue
		}

		fmt.Printf("%d ", i)
	}
	fmt.Println()

	// print the star sequence (nested loop)
	fmt.Println("\n\nLet's print with nested loop")
	n := 5
	for i := 1; i <= n; i++ {
		for j := 1; j <= i; j++ {
			fmt.Print("*")
		}
		fmt.Println()
	}

	// print the christmas tree
	fmt.Println("\n\nLet's print the christmas tree:")
	height := 10

	for i := 1; i <= height; i++ {
		for j := 1; j <= 3*n-i; j++ {
			fmt.Print(" ")
		}

		for j := 1; j <= (2*i - 1); j++ {
			fmt.Print("*")
		}

		fmt.Println()
	}
}
