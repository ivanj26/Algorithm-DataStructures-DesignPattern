package main

import (
	"fmt"
	"net/http"
)

func checkWebStatus(url string, c chan string) {
	_, err := http.Get(url)

	if err != nil {
		c <- fmt.Sprintf("url: %s might be down!\n", url)
		return
	}

	c <- fmt.Sprintf("%s OK!\n", url)
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

	for i := 0; i < len(urls); i++ {
		fmt.Print(<-c)
	}
}
