// A. Order Book Matching (Two-Pointer/Hash Map)
// Question:

// Implement a simplified order book matching engine.
// Given a list of buy orders (price, quantity) and sell orders (price, quantity),
// match them first by price (buy >= sell) and then by time (FIFO). Return the matched trades.

package main

import (
	"fmt"
	"sort"
	"time"
)

type Order struct {
	Price     float64
	Quantity  float64
	PlaceTime time.Time
	IsBuy     bool
}

type Trade struct {
	Price    float64
	Quantity float64
}

// Buyorders = [100:2, 99:1, 98:1]
// Sellorders = [99:1, 100:1, 101:1]

// trades <- array

// 1st Approach: Match order by sorting both orders
//  1. Sort buyorders by price descending. If the price is same, sort by time ascending
//  2. Sort sellorders by price ascending. If the price is same, sort by time ascending
//  3. Check untuk setiap buy order:
//     3.0  Quantity buy order > 0 && Quantity sell order > 0
//     3.0.1. Apakah buy order price >= sell order
//     3.0.2  min_quantity = min(buy_order.quantity, sell_order.quantity)
//     3.0.3  buy_order.Quantity -= min_qty
//     3.0.4  sell_order.Quantity -= min_qty
//     trades = append(trades, Trade{qty: min_qty, price: 99})
//     3.0.5  if buy_order.qty == 0
//     break the loop
//     3.0.6  if sell_order.qty == 0
//     continue
func minFloat(a, b float64) float64 {
	if a > b {
		return b
	}

	return a
}

func MatchOrders(buyOrders []Order, sellOrders []Order) []Trade {
	var trades []Trade = make([]Trade, 0)

	sort.Slice(buyOrders, func(i, j int) bool {
		if buyOrders[i].Price == buyOrders[j].Price {
			return buyOrders[i].PlaceTime.Before(buyOrders[j].PlaceTime)
		}

		return buyOrders[i].Price > buyOrders[j].Price
	})

	sort.Slice(sellOrders, func(i, j int) bool {
		if sellOrders[i].Price == sellOrders[j].Price {
			return sellOrders[i].PlaceTime.Before(sellOrders[j].PlaceTime)
		}

		return sellOrders[i].Price < sellOrders[j].Price
	})

	// Algorihtm matching order
	for i := 0; i < len(buyOrders) && len(sellOrders) > 0; i++ {
		buy := &buyOrders[i]

		for j := 0; j < len(sellOrders); j++ {
			sell := &sellOrders[j]

			if buy.Quantity == 0 {
				break
			}

			if buy.Price >= sell.Price && buy.Quantity > 0 && sell.Quantity > 0 {
				minQty := minFloat(buy.Quantity, sell.Quantity)
				trades = append(trades, Trade{
					Quantity: minQty,
					Price:    sell.Price, // best price
				})

				buy.Quantity -= minQty
				sell.Quantity -= minQty

				if sell.Quantity == 0 {
					sellOrders = sellOrders[1:]
					j--
					continue
				}
			}
		}
	}

	return trades
}

func main() {
	// Example buy and sell orders
	buyOrders := []Order{
		{Price: 101, Quantity: 1, PlaceTime: time.Date(2023, 1, 1, 9, 1, 0, 0, time.UTC), IsBuy: false},
		{Price: 100, Quantity: 5, PlaceTime: time.Date(2023, 1, 1, 9, 0, 0, 0, time.UTC), IsBuy: true},
		{Price: 99, Quantity: 3, PlaceTime: time.Date(2023, 1, 1, 9, 1, 0, 0, time.UTC), IsBuy: true},
	}
	sellOrders := []Order{
		{Price: 99, Quantity: 2, PlaceTime: time.Date(2023, 1, 1, 9, 0, 0, 0, time.UTC), IsBuy: false},
		{Price: 100, Quantity: 4, PlaceTime: time.Date(2023, 1, 1, 9, 1, 0, 0, time.UTC), IsBuy: false},
	}

	trades := MatchOrders(buyOrders, sellOrders)
	for _, trade := range trades {
		fmt.Printf("Executed trade: (Price: %.2f, Qty: %.2f)\n", trade.Price, trade.Quantity)
	}

	fmt.Println("\n\nRemaining running orders:\n")
	for _, buyorder := range buyOrders {
		fmt.Printf("Buy order: (Price: %.2f, Qty: %.2f)\n", buyorder.Price, buyorder.Quantity)
	}

	for _, sellorder := range sellOrders {
		fmt.Printf("Sell order: (Price: %.2f, Qty: %.2f)\n", sellorder.Price, sellorder.Quantity)
	}
}
