package main

import "fmt"

func main() {
	// scan the x value
	var x int
	fmt.Scanf("%d", &x)

	// switch case
	switch {
	case x < 50:
		fmt.Println("x is less than 50")
	case x >= 50 && x < 100:
		fmt.Println("x is equal or greater than 50 but less than 100")
	case x >= 100:
		fmt.Println("x is equal or greater than 100")
	default:
		fmt.Println("enter the default case")
	}

	// scan the y value
	var y int
	fmt.Scanf("%d", &y)

	// switch case using fallthrough
	switch {
	case y < 50:
		fmt.Println("y is less than 50")
	case y >= 50 && y < 100:
		fmt.Println("y is equal or greater than 50 but less than 100")
		fallthrough
	case y >= 100:
		fmt.Println("y is equal or greater than 100")
	default:
		fmt.Println("enter the default case")
	}
}
