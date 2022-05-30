package main

import (
	"fmt"
	"net/http"
)

func checkWebStatus(url string, c chan string) {
	_, err := http.Get(url)

	if err != nil {
		fmt.Printf("%s might be down\n", url)
		c <- url

		return
	}

	fmt.Printf("%s OK!\n", url)
	c <- url
}

func main() {
	urls := []string{
		"https://google.com",
		"https://facebook.com",
		"https://twitter.com",
		"https://golang.org",
	}

	c := make(chan string)
	for _, url := range urls {
		go checkWebStatus(url, c)
	}

	for l := range c {
		go checkWebStatus(l, c)
	}
}
