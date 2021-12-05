package main

import "fmt"

func main() {
	// Get input from I/O
	var x int
	fmt.Scanf("%d", &x)

	if x > 0 {
		fmt.Printf("x is greater than zero, x = %d\n", x)
	} else {
		fmt.Printf("x is less than zero, x = %d\n", x)
	}
}
