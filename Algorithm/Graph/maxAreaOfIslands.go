package main

// Problem: https://leetcode.com/problems/max-area-of-island/?envType=study-plan&id=graph-i

// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.)
// You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.
// Return the maximum area of an island in grid. If there is no island, return 0.

func visitIsland(grid [][]int, x, y int) int {
	// Mark as visited. Fill with other number.
	grid[x][y] = 2
	count := 0

	// Check boundaries
	// Top
	if y-1 >= 0 && grid[x][y-1] == 1 {
		count += 1 + visitIsland(grid, x, y-1)
	}

	// Bottom
	if y+1 < len(grid[0]) && grid[x][y+1] == 1 {
		count += 1 + visitIsland(grid, x, y+1)
	}

	// Left
	if x-1 >= 0 && grid[x-1][y] == 1 {
		count += 1 + visitIsland(grid, x-1, y)
	}

	// Right
	if x+1 < len(grid) && grid[x+1][y] == 1 {
		count += 1 + visitIsland(grid, x+1, y)
	}

	return count
}

func GetMax(x, y int) int {
	if x > y {
		return x
	}

	return y
}

func maxAreaOfIsland(grid [][]int) int {
	max := 0

	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == 1 {
				area := 1 + visitIsland(grid, i, j)
				max = GetMax(area, max)
			}
		}
	}

	return max
}
