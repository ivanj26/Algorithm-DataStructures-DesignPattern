package main

import "math"

func reverse(int x) int {
	var signed bool = false
	if x < 0 {
		signed = true
		x *= -1
	}

	reversed := 0
	for {
		// Get last digit of x
		modulo := x % 10

		if x > 0 {
			// Check if out of range or not
			if ((reversed * 10) + modulo) > math.MaxInt32 {
				return 0
			}

			// Calculate the result
			reversed *= 10
			reversed += modulo

			// Next iteration: Divide x by 10
			// Need to move pointer to next digit
			x = x / 10
		} else { // Let say, x == 0
			break
		}
	}

	if signed {
		// Is out of range?
		if reversed*-1 < math.MinInt32 {
			return 0
		}

		return reversed * -1
	}

	return reversed
}
