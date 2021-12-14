package main

import "fmt"

func hello(num int, nums ...int) {
	fmt.Printf("Type of nums: %T\n", nums)

	found := false

	for i, val := range nums {
		if val == num {
			fmt.Printf("Val %d found at index %d in nums array ", val, i)
			fmt.Println(nums)

			found = true
		}

		if found {
			break
		}
	}

	if !found {
		fmt.Printf("Val %d is not found\n", num)
	}
}

func main() {
	hello(89, 90, 91, 89)
}
