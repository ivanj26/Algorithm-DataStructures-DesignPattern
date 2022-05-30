package main

import (
	"fmt"
	"log"
)

// HashNode...
type HashNode struct {
	Key  string
	Next *HashNode
}

func (h *HashNode) GetNext() *HashNode {
	return h.Next
}

func (h *HashNode) SetNext(next *HashNode) {
	h.Next = next
}

func (h *HashNode) GetKey() string {
	return h.Key
}

func (h *HashNode) SetKey(key string) {
	h.Key = key
}

// HashFunction
type HashFunction func(string) uint32

// HashSet...
type HashSet struct {
	Table      []*HashNode
	BucketSize int
	KeySize    int
	Hash       HashFunction
}

// interface IHashSet
// should implement by HashSet object
type IHashSet interface {
	Insert(key string)
	Exists(key string) bool
	Size() int
	Clear()
}

const BUCKET_SIZE = 256

func NewHashSet() IHashSet {
	return &HashSet{
		Table:      make([]*HashNode, BUCKET_SIZE),
		BucketSize: BUCKET_SIZE,
		KeySize:    0,
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

func getIndex(hashValue uint32, size int) int {
	return int(hashValue) % size
}

func (h *HashSet) Insert(key string) {
	hashValue := h.Hash(key)
	idx := getIndex(hashValue, h.BucketSize)

	var (
		entry *HashNode
		prev  *HashNode
	)

	entry = h.Table[idx]

	for entry != nil {
		if entry.Key != key {
			prev = entry
			entry = entry.Next
		} else {
			log.Printf("Key: %v has been added before!", key)
			log.Println()

			break
		}
	}

	if entry == nil {
		entry = new(HashNode)
		entry.Key = key

		if prev == nil {
			// Set as first entry
			h.Table[idx] = entry
		} else {
			prev.SetNext(entry)
		}

		h.KeySize++
	}
}

func (h *HashSet) Exists(key string) bool {
	hashValue := h.Hash(key)
	idx := getIndex(hashValue, h.BucketSize)

	entry := h.Table[idx]
	for entry != nil {
		if entry.Key == key {
			return true
		} else {
			entry = entry.Next
		}
	}

	return false
}

func (h *HashSet) Size() int {
	return h.KeySize
}

func (h *HashSet) Clear() {
	h.Table = make([]*HashNode, h.BucketSize)
	h.KeySize = 0
}

func PrintHashSetSize(s IHashSet) {
	fmt.Printf("Key size of Set: %v\n", s.Size())
}

func main() {
	set := NewHashSet()
	set.Insert("test1")
	set.Insert("test2")
	set.Insert("test3")

	// Print HashSet key size
	PrintHashSetSize(set)
	fmt.Printf("Is %v exists? : %v\n", "test1", set.Exists("test1"))

	// clear the elements
	set.Clear()

	// Print again
	PrintHashSetSize(set)
	fmt.Printf("Is %v exists? : %v\n", "test1", set.Exists("test1"))
}
