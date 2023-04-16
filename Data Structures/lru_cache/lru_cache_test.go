package lru_cache

import (
	"fmt"
	"strconv"
	"testing"

	"github.com/stretchr/testify/assert"
)

const (
	CAPACITY = 2
)

type Operation int

const (
	GET_OPERATION Operation = iota
	PUT_OPERATION
)

func TestLRUCache(t *testing.T) {
	cache := NewLRUCache(CAPACITY)

	// Operation list
	tests := []struct {
		operation Operation
		key       int
		value     int
		expect    interface{}
		expectErr error
	}{
		{
			operation: PUT_OPERATION,
			key:       1,
			value:     1,
			expect:    nil,
			expectErr: nil,
		},
		{
			operation: PUT_OPERATION,
			key:       2,
			value:     2,
			expect:    nil,
			expectErr: nil,
		},
		{
			operation: GET_OPERATION,
			key:       1,
			expect:    1,
			expectErr: nil,
		},
		{
			operation: PUT_OPERATION,
			key:       3,
			value:     3,
			expect:    nil,
			expectErr: nil,
		},
		{
			operation: GET_OPERATION,
			key:       2,
			expect:    -1,
			expectErr: fmt.Errorf("Key is not found"),
		},
		{
			operation: PUT_OPERATION,
			key:       4,
			value:     4,
			expect:    nil,
			expectErr: nil,
		},
		{
			operation: GET_OPERATION,
			key:       1,
			expect:    -1,
			expectErr: fmt.Errorf("Key is not found"),
		},
		{
			operation: GET_OPERATION,
			key:       3,
			expect:    3,
			expectErr: nil,
		},
		{
			operation: GET_OPERATION,
			key:       4,
			expect:    4,
			expectErr: nil,
		},
	}

	for _, tt := range tests {
		t.Run("Check test LRUCache", func(t *testing.T) {
			k := strconv.Itoa(tt.key)

			if tt.operation == PUT_OPERATION {
				cache.Put(k, tt.value)
			} else {
				v, err := cache.GetAsInt(k)

				assert.Equal(t, tt.expectErr, err)
				assert.Equal(t, tt.expect, v)
			}
		})
	}
}
