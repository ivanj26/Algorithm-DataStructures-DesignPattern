package main

import (
	"container/list"
	"fmt"
	"math/rand"
	"strconv"
	"time"
)

// internal struct
type item struct {
	Key   string
	Value interface{}
}

type LRUCache struct {
	Capacity int
	Queue    *list.List
	Items    map[string]*list.Element
}

func NewLRUCache(capacity int) LRUCache {
	return LRUCache{
		Capacity: capacity,
		Queue:    list.New(),
		Items:    make(map[string]*list.Element),
	}
}

func (this LRUCache) GetAsInt(key string) (int, error) {
	// Check if the key exists or not
	if it, ok := this.Items[key]; ok {
		this.Queue.MoveToFront(it) // O(1) to make item to be most recently accessed
		return it.Value.(item).Value.(int), nil
	}

	// Return -1 if the key is not found
	return -1, fmt.Errorf("Key is not found")
}

func (this LRUCache) GetAsFloat64(key string) (float64, error) {
	// Check if the key exists or not
	if it, ok := this.Items[key]; ok {
		this.Queue.MoveToFront(it) // O(1) to make item to be most recently accessed
		return it.Value.(item).Value.(float64), nil
	}

	// Return -1 if the key is not found
	return -1, fmt.Errorf("Key is not found")
}

func (this LRUCache) GetAsString(key string) (string, error) {
	// Check if the key exists or not
	if it, ok := this.Items[key]; ok {
		this.Queue.MoveToFront(it) // O(1) to make item to be most recently accessed
		return it.Value.(item).Value.(string), nil
	}

	// Return -1 if the key is not found
	return "", fmt.Errorf("Key is not found")
}

func (this LRUCache) Put(key string, val interface{}) {
	if it, ok := this.Items[key]; ok {
		v := it.Value.(item)
		v.Value = val // override the existing value

		it.Value = v
		this.Items[key] = it
		this.Queue.MoveToFront(it) // O(1) to make item to be most recently updated
	} else {
		// If the capacity of LRUCache is full
		// Remove from map and queue
		if this.Capacity == len(this.Items) {
			back := this.Queue.Back()
			delete(this.Items, key)
			this.Queue.Remove(back)
		}

		// Insert new item into map and queue
		newItem := item{Key: key, Value: val}
		this.Items[key] = this.Queue.PushFront(newItem)
	}
}

func main() {
	cache := NewLRUCache(5)

	rand.Seed(time.Now().Unix())

	for i := 1; i < 10; i += 1 {
		rnd := rand.Intn(10) + 1

		key := strconv.Itoa(rnd)
		cache.Put(key, "1")
	}
}
