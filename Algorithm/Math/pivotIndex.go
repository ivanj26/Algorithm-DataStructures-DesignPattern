package main

import "fmt"

func pivotIndex(nums []int) int {
	var (
		totalSum int = 0
		leftSum  int = 0
	)

	// Traverse array, sum all the nums, and store it to totalSum
	for _, val := range nums {
		totalSum += val
	}

	// Traverse again and check whether the leftSum == totalSum or not
	// In each loop, subtract the totalSum with value in current index
	for i := 0; i < len(nums); i++ {
		totalSum -= nums[i]

		// If the right sum is equals with leftSum
		// Return pivot index
		if totalSum == leftSum {
			return i
		}

		leftSum += nums[i]
	}

	return -1
}

func main() {
	pivIndex := pivotIndex([]int{1, 7, 3, 6, 5, 6})
	fmt.Println("Pivot index: ", pivIndex)
}
