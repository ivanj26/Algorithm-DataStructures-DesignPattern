package main

import (
	"encoding/json"
	"fmt"

	"github.com/go-redis/redis"
)

type Author struct {
	Name string `json:"name"`
	Age  int    `json:"age"`
}

func printList(list []string) {
	for i, elmt := range list {
		fmt.Println(i+1, ". ", elmt)
	}
}

func main() {
	client := redis.NewClient(
		&redis.Options{
			Addr:     "localhost:6379",
			Password: "pass123",
			DB:       0,
		},
	)

	// Test redis connection
	pong, err := client.Ping().Result()
	fmt.Println(pong, err)

	/**
	*	STRING
	**/
	// Set() string data structure
	jsonByte, err := json.Marshal(Author{
		Name: "Ivan Jonathan",
		Age:  22,
	})
	if err != nil {
		fmt.Println("Failed to marshal the json!")
	}

	_, err = client.Set("nakama", string(jsonByte), 0).Result()
	if err != nil {
		fmt.Println(err)
	}

	// Get() string data structure
	val, err := client.Get("nakama").Result()
	if err != nil {
		fmt.Printf("Error happends when get redis value, err: %s\n", err.Error())
	}
	var author Author
	err = json.Unmarshal([]byte(val), &author)

	if err != nil {
		fmt.Println("Failed to unmarshal the json!")
	}

	fmt.Println("Value of nakama = ", author.Name, ", ", author.Age)

	/**
	*	LIST
	**/
	client.Del("nakama_list")

	// LPush() list data structure
	client.LPush("nakama_list", "elmt1", "elmt2", "elmt2")

	// LRange()
	l := client.LRange("nakama_list", 0, -1).Val()

	fmt.Println("List of nakama_list:")
	printList(l)

	// Rpush() list data structure, push to right side
	client.RPush("nakama_list", "elmt3")
	l = client.LRange("nakama_list", 0, -1).Val()

	fmt.Println("\nAfter RPush()")
	fmt.Println("List of nakama_list:")
	printList(l)
}
