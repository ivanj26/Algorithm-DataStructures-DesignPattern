package main

import "fmt"

type A struct {
	IndexStart int
	Sum        int
}

func sum(arr []int, start int, c chan A) {
	sum := 0

	for _, v := range arr {
		sum += v
	}

	c <- A{
		IndexStart: (start / len(arr)),
		Sum:        sum,
	}
}

func main() {
	a := []int{17, 12, 18, 9, 24, 42, 64, 12, 68, 82, 57, 32, 9, 2, 12, 82, 52, 34, 92, 36}

	var (
		chunkLength = 5
		chunkGroup  = len(a) / chunkLength
	)

	c := make(chan A)
	for i := 0; i < len(a); i = i + chunkLength {
		start := i
		go sum(a[start:start+chunkLength], start, c)
	}
	output := make([]int, chunkGroup)
	for i := 0; i < chunkGroup; i++ {
		val := <-c

		output[val.IndexStart] = val.Sum
	}
	close(c)

	fmt.Println(output)
}
