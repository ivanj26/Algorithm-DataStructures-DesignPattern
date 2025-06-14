package main

import (
	"fmt"
	"sort"
	"strings"
)

type Pair struct {
	first  int  // log the frequency of each character
	second rune // character
}

func frequencySort(s string) string {
	freqMap := make(map[rune]int)

	for _, ch := range s {
		freqMap[ch]++
	}

	var arr []Pair
	for ch, freq := range freqMap {
		arr = append(arr, Pair{first: freq, second: ch})
	}

	sort.Slice(arr, func(i, j int) bool {
		if arr[i].first == arr[j].first {
			return arr[i].second < arr[j].second // ascending by lexicographically if the frequency is same
		}

		return arr[i].first > arr[j].first // sorting by freq (descending)
	})

	// Current State, arr is sorted descending by freq
	var sb strings.Builder
	for i := 0; i < len(arr); i++ {
		var p Pair = arr[i]

		sb.WriteString(strings.Repeat(string(p.second), p.first))
	}

	return sb.String()
}

func main() {
	fmt.Println(frequencySort("tree"))
	fmt.Println(frequencySort("cccaaa"))
	fmt.Println(frequencySort("Aabb"))
}
