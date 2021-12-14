package main

import "fmt"

func iterate(m map[string]int) {
	// iterate over all elements in map[string] int
	for key, value := range m {
		fmt.Printf("Key: %s, Val: %d\n", key, value)
	}
}

func main() {
	employeeSal := make(map[string]int)

	employeeSal["a"] = 100000
	employeeSal["b"] = 200000
	employeeSal["c"] = 300000

	// iterate over all elements
	iterate(employeeSal)

	// delete key
	delete(employeeSal, "b")

	// iterate after delete
	iterate(employeeSal)
}
