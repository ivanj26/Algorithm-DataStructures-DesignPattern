package main

import "fmt"

func reverseString(s []byte) {
	total := len(s) - 1

	for i, _ := range s {
		if i <= (total / 2) {
			tmp := s[total-i]
			s[total-i] = s[i]
			s[i] = tmp
		}
	}
}

func print(s []byte) {
	for i := 0; i < len(s); i++ {
		fmt.Printf("%+v ", s[i])
	}
	fmt.Println()
}

func main() {
	var arr []byte = []byte{3, 4, 5, 6, 7}

	// Print the array
	print(arr)

	// Reverse the array
	reverseString(arr)

	// Print the array again
	print(arr)
}
