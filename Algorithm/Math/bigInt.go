package main

import (
	"fmt"
	"math/big"
)

func computeProduct(s string, MAX_SIZE int64) int64 {
	product := big.NewInt(1)
	for i, ch := range s {
		ascii := int64(ch)
		term := new(big.Int).Exp(big.NewInt(ascii), big.NewInt(int64(i+1)), nil)

		product.Mul(product, term)
	}

	return product.Mod(product, big.NewInt(MAX_SIZE)).Int64()
}

func main() {
	fmt.Println(computeProduct("hello", 20))
}
