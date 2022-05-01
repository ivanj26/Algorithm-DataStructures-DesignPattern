package main

import (
	"math"
	"testing"
)

func TestGet(t *testing.T) {
	t.Run("Test 1: when hashmap is empty", func(t *testing.T) {
		hmap := NewHashMap()

		val, err := hmap.Get("key1")
		if val != math.MinInt {
			t.Errorf("expectation: %d, actual: %d", math.MinInt, val)
		}

		if err == nil {
			t.Error("expectation: not nil, actual: nil")
		}
	})

	t.Run("Test 2: when given key is exists in hashmap", func(t *testing.T) {
		hmap := NewHashMap()
		k := "key1"
		v := 1

		hmap.Put(k, v)

		val, err := hmap.Get(k)
		if val != v {
			t.Errorf("expectation: %d, actual: %d", math.MinInt, val)
		}

		if err != nil {
			t.Error("expectation: nil, actual: not nil")
		}
	})
}

func TestPut(t *testing.T) {
	hmap := NewHashMap()
	hmap.Put("key1", 1)
	hmap.Put("key2", 2)
	hmap.Put("key3", 3)

	keys := hmap.Keys()
	actualKeys := map[string]bool{
		"key1": false,
		"key2": false,
		"key3": false,
	}

	for _, k := range keys {
		if val, ok := actualKeys[k]; ok {
			if val == false {
				actualKeys[k] = true
				// skip
			} else {
				t.Error("redundant key")
			}
		} else {
			t.Errorf("expectation: key %s should exists in hashmap, actual: key %s is not exists", k, k)
		}
	}

	for k, v := range actualKeys {
		if v == false {
			t.Errorf("expectation: key %s is visited, actual: key %s is not visited", k, k)
		}
	}
}

func TestRemove(t *testing.T) {
	t.Run("Test 1: if error is not occured", func(t *testing.T) {
		hmap := NewHashMap()
		hmap.Put("key1", 1)
		hmap.Put("key2", 2)
		hmap.Put("key3", 3)

		err := hmap.Remove("key2")
		if err != nil {
			t.Error("expectation: error should not occurs, actual: error is occurs")
		}

		keys := hmap.Keys()
		actualKeys := map[string]bool{
			"key1": false,
			"key3": false,
		}

		for _, k := range keys {
			if val, ok := actualKeys[k]; ok {
				if val == false {
					actualKeys[k] = true
					// skip
				} else {
					t.Error("redundant key")
				}
			} else {
				t.Errorf("expectation: key %s should exists in hashmap, actual: key %s is not exists", k, k)
			}
		}

		for k, v := range actualKeys {
			if v == false {
				t.Errorf("expectation: key %s is visited, actual: key %s is not visited", k, k)
			}
		}
	})

	t.Run("Test 2: if error is occured", func(t *testing.T) {
		hmap := NewHashMap()
		hmap.Put("key1", 1)
		hmap.Put("key3", 3)
		hmap.Put("key4", 4)
		hmap.Put("key5", 5)

		err := hmap.Remove("key2")
		if err == nil {
			t.Error("expectation: error is not nil, actual: error is nil")
		}
	})
}
