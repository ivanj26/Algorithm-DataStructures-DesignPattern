// Problem: https://leetcode.com/problems/rotting-oranges/description/?envType=study-plan&id=algorithm-i
package main

import "container/list"

// You are given an m x n grid where each cell can have one of three values:

// - 0 representing an empty cell,
// - 1 representing a fresh orange, or
// - 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

func orangesRotting(grid [][]int) int {
	q := list.New()
	maxDepth := 0

	// Check if grid cell value is 2 or not
	// If yes, push it to the queue.
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == 2 {
				q.PushBack([]int{i, j, 0})
			}
		}
	}

	// Iterate using BFS style
	for q.Front() != nil {
		curr := (q.Front().Value).([]int)
		x := curr[0]
		y := curr[1]

		// Remove front element
		q.Remove(q.Front())

		// Check whether the index is out of bound or not
		// Pass to the next elmt if true
		if x < 0 || x >= len(grid) || y < 0 || y >= len(grid[0]) {
			continue
		}

		// Check whether the cell value is empty or already visited
		// Note: We will marking visited cell with value of 3
		if grid[x][y] == 0 || grid[x][y] == 3 {
			continue
		}

		// Mark as visited cell
		grid[x][y] = 3

		// If current depth is greater than max depth
		// Replace it
		currDepth := curr[2]
		if maxDepth < currDepth {
			maxDepth = currDepth
		}

		q.PushBack([]int{x, y + 1, currDepth + 1})
		q.PushBack([]int{x + 1, y, currDepth + 1})
		q.PushBack([]int{x - 1, y, currDepth + 1})
		q.PushBack([]int{x, y - 1, currDepth + 1})
	}

	// Check if the grid still has value of 1 (if fresh orange is remaining in somewhere else)
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == 1 {
				return -1
			}
		}
	}

	return maxDepth
}
