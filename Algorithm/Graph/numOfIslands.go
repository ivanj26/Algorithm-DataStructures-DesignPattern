package main

// Problem: https://leetcode.com/problems/number-of-islands/

func markAsVisited(grid [][]byte, x, y int) {
	// Mark with another character to indicate the cell is already visited
	grid[x][y] = '2'

	// Check boundaries
	// Bottom
	if y+1 < len(grid[0]) && grid[x][y+1] == '1' {
		markAsVisited(grid, x, y+1)
	}

	// Top
	if y-1 >= 0 && grid[x][y-1] == '1' {
		markAsVisited(grid, x, y-1)
	}

	// Left
	if x-1 >= 0 && grid[x-1][y] == '1' {
		markAsVisited(grid, x-1, y)
	}

	// Right
	if x+1 < len(grid) && grid[x+1][y] == '1' {
		markAsVisited(grid, x+1, y)
	}
}

func numIslands(grid [][]byte) int {
	ans := 0

	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == '1' {
				ans += 1
				markAsVisited(grid, i, j)
			}
		}
	}

	return ans
}
