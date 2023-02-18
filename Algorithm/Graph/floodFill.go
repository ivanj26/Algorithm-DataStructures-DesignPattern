package main

import "container/list"

func floodFill(image [][]int, sr int, sc int, color int) [][]int {
	n := len(image)
	m := len(image[0])
	visited := make([][]bool, n)
	for i := range visited {
		visited[i] = make([]bool, m)
	}

	q := list.New()
	q.PushBack([]int{sr, sc})

	c := image[sr][sc]

	for q.Len() > 0 {
		coor := (q.Back().Value).([]int)
		q.Remove(q.Back())

		x := coor[0]
		y := coor[1]

		if image[x][y] != c {
			continue
		}

		if visited[x][y] == true {
			continue
		}

		if visited[x][y] == false && image[x][y] == c {
			image[x][y] = color
			visited[x][y] = true
		}

		// Top
		if y-1 >= 0 && y < m {
			q.PushBack([]int{x, y - 1})
		}

		// Right
		if x+1 < n {
			q.PushBack([]int{x + 1, y})
		}

		// Left
		if x-1 >= 0 {
			q.PushBack([]int{x - 1, y})
		}

		// Bottom
		if y+1 < m {
			q.PushBack([]int{x, y + 1})
		}
	}

	return image
}
