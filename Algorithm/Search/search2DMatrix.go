package main

// You are given an m x n integer matrix matrix with the following two properties:
// - Each row is sorted in non-decreasing order.
// - The first integer of each row is greater than the last integer of the previous row.

// Given an integer target, return true if target is in matrix or false otherwise.

func binSearch(nums []int, start, end, target int) bool {
	if start <= end {
		idxMid := start + (end-start)/2
		if nums[idxMid] == target {
			return true
		} else if target > nums[idxMid] {
			return binSearch(nums, idxMid+1, end, target)
		} else {
			return binSearch(nums, start, idxMid-1, target)
		}
	}

	return false
}

func searchMatrix(matrix [][]int, target int) bool {
	for i := 0; i < len(matrix); i++ {
		arr := matrix[i]

		if binSearch(arr, 0, len(arr)-1, target) {
			return true
		}
	}

	return false
}
