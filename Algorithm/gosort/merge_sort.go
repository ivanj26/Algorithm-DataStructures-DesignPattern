package main

type MergeSort struct {
	items    []int
	isSorted bool
}

func NewMergeSort(items []int, algo SortAlgorithm) *MergeSort {
	return &MergeSort{
		items: items,
	}
}

func (m *MergeSort) Perform() []int {
	if m.isSorted {
		return m.items
	}

	m.split(0, len(m.items))
	m.isSorted = true

	return m.items
}

func (m *MergeSort) split(left int, right int) {
	// Basis of recursion:
	// If only 1 element left
	if right-left < 2 {
		return
	}

	middle := (right + left) / 2
	m.split(left, middle)
	m.split(middle, right)

	m.merge(left, middle, right)
}

func (m *MergeSort) merge(left, middle, right int) {
	j := middle
	i := left
	s := []int{}

	for i < middle && j < right {
		if m.items[i] < m.items[j] {
			s = append(s, m.items[i])
			i++
		} else {
			s = append(s, m.items[j])
			j++
		}
	}

	for i < middle {
		s = append(s, m.items[i])
		i++
	}

	for j < right {
		s = append(s, m.items[j])
		j++
	}

	for i = left; i < right; i++ {
		m.items[i] = s[i-left]
	}
}
