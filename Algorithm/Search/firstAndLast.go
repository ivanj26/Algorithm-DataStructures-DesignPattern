package main

func searchLastIndex(nums []int, target, first, end int) []int {
	var last int = first
	for i := first + 1; i <= end; i++ {
		if target == nums[i] {
			last = i
		}
	}

	return []int{first, last}
}

func searchRangeUtil(nums []int, start, end, target int) []int {
	if start <= end {
		idxMid := start + ((end - start) / 2)
		mid := nums[idxMid]

		if mid == target {
			s := idxMid
			for u := idxMid; u >= start; u-- {
				if nums[u] == target {
					s = u
				} else {
					break
				}
			}
			return searchLastIndex(nums, target, s, end)
		} else if target > mid {
			return searchRangeUtil(nums, idxMid+1, end, target)
		} else {
			return searchRangeUtil(nums, start, idxMid-1, target)
		}
	}

	return []int{-1, -1}
}

func searchRange(nums []int, target int) []int {
	start := 0
	end := len(nums) - 1

	return searchRangeUtil(nums, start, end, target)
}
