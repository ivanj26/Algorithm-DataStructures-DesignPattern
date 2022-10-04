package main

import (
	"fmt"
	"log"
	"net/http"
	"sync"
)

var urls = []string{
	"https://google.com",
	"https://tutorialedge.net",
	"https://twitter.com",
}

func fetch(url string, wg *sync.WaitGroup) {
	defer wg.Done()

	res, err := http.Get(url)
	if err != nil {
		log.Println(err.Error())
	}

	log.Println(res.Status)
}

func homePageHandler(w http.ResponseWriter, req *http.Request) {
	fmt.Println("Homepage Handler hit!")

	var wg sync.WaitGroup

	for _, url := range urls {
		wg.Add(1)

		go fetch(url, &wg)
	}

	wg.Wait()

	log.Println("All responses received...")
	fmt.Fprint(w, "Responses")
}

func main() {
	http.HandleFunc("/", homePageHandler)

	log.Println("Serve at :8080")
	log.Fatal(
		http.ListenAndServe(":8080", nil),
	)
}
