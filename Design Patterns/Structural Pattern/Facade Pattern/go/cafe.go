package main

import "fmt"

func makeAmericano(size float32) {
	fmt.Println("\nAmericano in The Making...")

	americano := &CoffeeMachine{}

	// determine beans amount to use - 5oz for every 8oz size
	beansAmount := (size / 8.0) * 5.0
	americano.startCoffee(beansAmount, 2)
	americano.grindBeans()
	americano.useHotWater(size)
	americano.endCoffee()

	fmt.Println("Americano is Ready!")
}

func makeLatte(size float32, foam bool) {
	fmt.Println("\nLatte in The Making...")

	latte := &CoffeeMachine{}

	// determine beans amount to use - 5oz for every 8oz size
	beansAmount := (size / 8.0) * 5.0
	latte.startCoffee(beansAmount, 2)
	latte.grindBeans()
	latte.useHotWater(size)

	// determine milk amount to use - 2oz for every 8oz size
	milk := 2.0 * (size / 8.0)
	latte.useMilk(milk)
	latte.doFoam(true)
	latte.endCoffee()

	fmt.Println("Latte is Ready!")
}
