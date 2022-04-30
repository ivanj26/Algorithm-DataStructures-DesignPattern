package main

import "fmt"

func main() {
	// Get input from I/O
	var x int
	fmt.Scanf("%d", &x)

	// then checking the value of x
	if x > 0 {
		fmt.Printf("x is greater than zero, x = %d\n", x)
	} else {
		fmt.Printf("x is less than zero, x = %d\n", x)
	}

	// Declare, initializing, and checking the value in one line
	if y := x + 10; y > 10 {
		fmt.Println("y is greater than ten, y = ", y)
	} else {
		fmt.Println("y is less or equal than ten, y = ", y)
	}
}
