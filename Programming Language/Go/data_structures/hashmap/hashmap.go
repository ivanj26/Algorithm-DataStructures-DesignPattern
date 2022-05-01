package main

import (
	"errors"
	"fmt"
	"math"
)

// HashNode..
type HashNode struct {
	Key  string
	Val  int
	Next *HashNode
}

func (h *HashNode) GetNext() *HashNode {
	return h.Next
}

func (h *HashNode) SetNext(next *HashNode) {
	h.Next = next
}

func (h *HashNode) SetKey(key string) {
	h.Key = key
}

func (h *HashNode) GetKey() string {
	return h.Key
}

func (h *HashNode) SetValue(val int) {
	h.Val = val
}

func (h *HashNode) GetValue() int {
	return h.Val
}

// HashFunction..
type HashFunction func(string) uint32

// HashMap..
type HashMap struct {
	Table []*HashNode
	Size  int
	Hash  HashFunction
}

const BUCKET_SIZE = 100

func NewHashMap() IHashMap {
	return &HashMap{
		Table: make([]*HashNode, BUCKET_SIZE),
		Size:  BUCKET_SIZE,
		Hash: func(key string) (hash uint32) {
			// Using Jenkins hash function
			hash = 0

			for _, char := range key {
				hash += uint32(char)
				hash += hash << 10
				hash ^= hash >> 6
			}

			hash += hash << 3
			hash ^= hash >> 11
			hash += hash << 15

			return hash
		},
	}
}

type IHashMap interface {
	Put(key string, val int)
	Remove(key string) error
	Get(key string) (int, error)
	Keys() (keys []string)
}

func getIndex(hash uint32, size int) int {
	return int(hash) % size
}

func (h *HashMap) Put(key string, val int) {
	hashValue := h.Hash(key)
	idx := getIndex(hashValue, h.Size)

	var (
		entry *HashNode
		prev  *HashNode
	)

	entry = h.Table[idx]

	for entry != nil {
		if entry.Key != key {
			prev = entry
			entry = entry.Next
		}
	}

	if entry == nil {
		entry = new(HashNode)
		entry.Key = key
		entry.Val = val

		if prev != nil {
			// Link the node with the previous one
			prev.SetNext(entry)
		} else {
			// Set as first entry
			h.Table[idx] = entry
		}

	} else {
		// Update value
		entry.SetValue(val)
	}
}

func (h *HashMap) Get(key string) (int, error) {
	hashValue := h.Hash(key)
	idx := getIndex(hashValue, h.Size)

	curr := h.Table[idx]
	for curr != nil {
		if curr.Key == key {
			return curr.Val, nil
		}

		curr = curr.Next
	}

	return math.MinInt, errors.New(fmt.Sprintf("Cannot find key: %s", key))
}

func (h *HashMap) Remove(key string) error {
	hashValue := h.Hash(key)
	idx := getIndex(hashValue, h.Size)

	var (
		entry *HashNode
		prev  *HashNode
	)

	entry = h.Table[idx]
	prev = nil

	for entry != nil && entry.Key != key {
		prev = entry
		entry = entry.GetNext()
	}

	if entry == nil {
		return errors.New(fmt.Sprintf("Cannot remove node with key: %s", key))
	}

	if prev != nil {
		next := entry.GetNext()
		prev.SetNext(next)
	} else {
		h.Table[idx] = entry.GetNext()
	}

	return nil
}

func (h *HashMap) Keys() (keys []string) {
	for i := 0; i < h.Size; i++ {
		if entry := h.Table[i]; entry != nil {
			for entry != nil {
				keys = append(keys, entry.GetKey())
				entry = entry.GetNext()
			}
		}
	}

	return
}

func main() {
	hmap := NewHashMap()
	hmap.Put("key1", 123)
	hmap.Put("key2", 132)
	hmap.Put("key3", 131)

	fmt.Println(hmap.Keys())
	fmt.Println()

	val, err := hmap.Get("key1")
	if err == nil {
		fmt.Print("Value of key1 is -> ")
		fmt.Println(val)
	}

	val, err = hmap.Get("key4")
	if err == nil {
		fmt.Print("Value of key4 is -> ")
		fmt.Println(val)
	} else {
		fmt.Println(err.Error())
	}

	err = hmap.Remove("key2")
	if err != nil {
		fmt.Println(err.Error())
	}

	err = hmap.Remove("key2")
	if err != nil {
		fmt.Println(err.Error())
	}

	fmt.Println(hmap.Keys())
}
