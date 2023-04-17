package main

func subsets(nums []int) [][]int {
	list := [][]int{}
	backtrack(&list, []int{}, nums, 0)

	return list
}

func backtrack(list *[][]int, tempList []int, nums []int, start int) {
	pathCopy := make([]int, len(tempList))
	copy(pathCopy, tempList)
	*list = append(*list, pathCopy)

	for i := start; i < len(nums); i++ {
		tempList = append(tempList, nums[i])
		backtrack(list, tempList, nums, i+1)
		tempList = tempList[:len(tempList)-1]
	}
}
