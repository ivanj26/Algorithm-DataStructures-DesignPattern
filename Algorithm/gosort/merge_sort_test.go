package main

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestMergeSort(t *testing.T) {
	tests := []struct {
		name   string
		items  []int
		expect []int
		sort   SortAlgorithm
	}{
		{
			name:   "merge sort test #1",
			items:  []int{2, 0, 2, 1, 1, 0},
			sort:   MERGE_SORT,
			expect: []int{0, 0, 1, 1, 2, 2},
		},
		{
			name:   "merge sort test #2",
			items:  []int{3, 0, 3, 1, 1, 0},
			sort:   MERGE_SORT,
			expect: []int{0, 0, 1, 1, 3, 3},
		},
		{
			name:   "merge sort test #3",
			items:  []int{2, 0, 1, -1, 1, 0},
			sort:   MERGE_SORT,
			expect: []int{-1, 0, 0, 1, 1, 2},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			s := NewSort(tt.items, MERGE_SORT)
			actual := s.Perform()

			assert.Equal(t, tt.expect, actual)
		})
	}
}
