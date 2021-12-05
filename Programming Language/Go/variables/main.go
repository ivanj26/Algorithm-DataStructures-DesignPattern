package main

import "fmt"

/**
* Variables
**/
func variables() {
	// Using `var`` if you want to declare the variable first and `assign later`
	var a int
	var b int
	a = 5
	b = 5

	fmt.Printf("%d + %d = %d\n", a, b, a+b)

	// Using () to grouping variable declarations
	var (
		d int
		e bool
	)
	d = 5
	e = false
	fmt.Printf("d is %d and e is %t\n", d, e)

	// Using `:=` if you want to assign the variable value in one step
	c := 5

	fmt.Printf("c is %d\n", c)

	// Multiple variable assignments
	f, g := 5, 5
	fmt.Printf("f is %d and g is %d\n", f, g)
}

/**
* Constants
**/
func constant() {
	const (
		a = 0
		b // implicitly assigned with 0
	)

	fmt.Printf("Const a = %d\n", a)
	fmt.Printf("Const b = %d\n", b)

	const (
		c        = 2
		d string = "string" // If not same type, just explicitly type it
	)

	fmt.Printf("Const c = %d\n", c)
	fmt.Printf("Const d = %s\n", d)
}

/**
* String
**/
func strings() {
	// String in GO is immutable
	// so, we will not able to change it value
	var s string = "Hello World!"
	// s[0] = 'c' <- This is illegal

	// There's other way
	// By using rune function, basically this rune function will converting the string to array of rune
	// Rune in GO is alias for int32 and is used to emphasize than an integer represents a code point
	c := []rune(s)
	c[0] = 'L'

	s2 := string(c)
	fmt.Println(s2)

	// Multiline string
	str := `Starting new
		string by declaring str`
	str2 := "Starting new " +
		"string by declaring str2"
	fmt.Println(str)
	fmt.Println(str2)
}

func main() {
	strings()
}
