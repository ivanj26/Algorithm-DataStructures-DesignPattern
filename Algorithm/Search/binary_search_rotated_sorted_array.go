package main

import "fmt"

// Given the array nums after the possible rotation and an integer target,
// return the index of target if it is in nums, or -1 if it is not in nums.
func search(nums []int, target int) int {
	left := 0
	right := len(nums) - 1

	for left <= right {
		mid := left + ((right - left) / 2)

		if nums[mid] == target {
			return mid
		}

		if nums[left] > nums[mid] {
			if target > nums[mid] && target <= nums[right] {
				left = mid + 1
			} else {
				right = mid - 1
			}
		} else {
			if target >= nums[left] && target < nums[mid] {
				right = mid - 1
			} else {
				left = mid + 1
			}
		}
	}

	return -1
}

func main() {
	inp, target := []int{4, 5, 6, 7, 0, 1, 2}, 0

	actual, expect := search(inp, target), 4

	fmt.Println("Actual: ", actual)
	fmt.Println("Expect: ", expect)
}
