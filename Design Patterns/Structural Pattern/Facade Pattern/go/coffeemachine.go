package main

import "fmt"

type CoffeeMachine struct {
	beanAmount   float32 // amount in ounces of beans to use
	grinderLevel int     // granularity of the bean grinder
	waterTemp    int     // temperature of the water to use
	waterAmt     float32 // amount of water
	milkAmt      float32 // amount of milk
	addForm      bool    // flag to identify whether to add foam or not
}

func (c *CoffeeMachine) startCoffee(beanAmount float32, grind int) {
	c.beanAmount = beanAmount
	c.grinderLevel = grind

	fmt.Println("Starting coffee order with beans: ", c.beanAmount, " and grind level: ", c.grinderLevel)
}

func (c *CoffeeMachine) endCoffee() {
	fmt.Println("Ending the coffee!")
}

func (c *CoffeeMachine) grindBeans() bool {
	fmt.Println("Grinding beans: ", c.beanAmount, " with level: ", c.grinderLevel)

	return true
}

func (c *CoffeeMachine) useMilk(milkAmt float32) float32 {
	fmt.Println("Using milk...")

	c.milkAmt = milkAmt
	return c.milkAmt
}

func (c *CoffeeMachine) setWaterTemp(temp int) {
	fmt.Println("Setting the water temp: ", temp)
}

func (c *CoffeeMachine) useHotWater(amount float32) float32 {
	fmt.Println("Adding hot water: ", amount)

	c.waterAmt = amount
	return c.waterAmt
}

func (c *CoffeeMachine) doFoam(useFoam bool) {
	fmt.Println("Foam setting: ", useFoam)
	c.addForm = useFoam
}
