package main

import (
	"fmt"
	"sort"
	"strings"
)

func frequencySort(s string) string {
	freqMp := make(map[rune]int)
	for _, ch := range s {
		freqMp[ch]++
	}

	type pair struct {
		ch    rune
		count int
	}
	var freqVector []pair
	for k, v := range freqMp {
		freqVector = append(freqVector, pair{
			ch:    k,
			count: v,
		})
	}

	sort.Slice(freqVector, func(i, j int) bool {
		if freqVector[i].count == freqVector[j].count { // if the frequency is same
			return freqVector[i].ch < freqVector[j].ch // ascending by ascii characters
		}

		return freqVector[i].count > freqVector[j].count // sort by frequency descending
	})

	var sb strings.Builder
	for _, p := range freqVector {
		sb.WriteString(strings.Repeat(string(p.ch), p.count))
	}

	return sb.String()
}

func main() {
	fmt.Println(frequencySort("bbbaac123333")) // Output: 3333bbbaa12
	fmt.Println(frequencySort("xyzxyzz"))      // Output: zzzxyyx
}
