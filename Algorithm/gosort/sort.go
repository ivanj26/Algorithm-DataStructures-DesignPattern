package main

type SortAlgorithm int

type Sort interface {
	Perform() []int
}

const (
	MERGE_SORT SortAlgorithm = iota
)

func NewSort(items []int, algo SortAlgorithm) Sort {
	if algo == MERGE_SORT {
		return NewMergeSort(items, algo)
	}

	return nil
}
