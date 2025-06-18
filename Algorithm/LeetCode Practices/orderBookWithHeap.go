package main

import (
	"container/heap"
	"fmt"
	"time"
)

type BuyHeap []Order
type SellHeap []Order

func (b BuyHeap) Len() int {
	return len(b)
}

func (b BuyHeap) Less(i, j int) bool {
	if b[i].Price == b[j].Price {
		return b[i].PlaceTime.Before(b[j].PlaceTime)
	}

	return b[i].Price > b[j].Price
}

func (b BuyHeap) Swap(i, j int) {
	b[i], b[j] = b[j], b[i]
}

func (b *BuyHeap) Push(x any) {
	*b = append(*b, x.(Order))
}

func (b *BuyHeap) Pop() any {
	if b.Len() == 0 {
		return nil
	}

	old := *b
	last := old[b.Len()-1]
	*b = old[:b.Len()-1]

	return last
}

func (b *BuyHeap) Peek() Order {
	if b.Len() == 0 {
		return Order{}
	}

	return (*b)[0]
}

// SellHeap
func (s SellHeap) Len() int {
	return len(s)
}

func (s SellHeap) Less(i, j int) bool {
	if s[i].Price == s[j].Price {
		return s[i].PlaceTime.Before(s[j].PlaceTime)
	}

	return s[i].Price < s[j].Price
}

func (s SellHeap) Swap(i, j int) {
	s[i], s[j] = s[j], s[i]
}

func (s *SellHeap) Push(x any) {
	*s = append(*s, x.(Order))
}

func (s *SellHeap) Pop() any {
	if s.Len() == 0 {
		return nil
	}

	old := *s
	last := old[s.Len()-1]
	*s = old[:s.Len()-1]

	return last
}

func (s *SellHeap) Peek() Order {
	if s.Len() == 0 {
		return Order{}
	}

	return (*s)[0]
}

func (b *BuyHeap) DecreaseTopQuantity(amount float64) {
	if len(*b) == 0 {
		return
	}
	(*b)[0].Quantity -= amount
	if (*b)[0].Quantity <= 0 {
		heap.Pop(b) // Remove if quantity exhausted
	} else {
		heap.Fix(b, 0) // Re-heapify
	}
}

func (s *SellHeap) DecreaseTopQuantity(amount float64) {
	if len(*s) == 0 {
		return
	}

	(*s)[0].Quantity -= amount
	if (*s)[0].Quantity <= 0 {
		heap.Pop(s) // Remove if quantity exhausted
	} else {
		heap.Fix(s, 0) // Re-heapify
	}
}

func MatchOrdersWithHeap(buyHeap *BuyHeap, sellHeap *SellHeap) []Trade {
	var trades []Trade

	for buyHeap.Len() > 0 && sellHeap.Len() > 0 {
		buy := buyHeap.Peek()
		sell := sellHeap.Peek()

		if buy.Price >= sell.Price && buy.Quantity > 0 && sell.Quantity > 0 {
			minQty := minFloat(buy.Quantity, sell.Quantity)
			trades = append(trades, Trade{
				Quantity: minQty,
				Price:    sell.Price,
			})

			sellHeap.DecreaseTopQuantity(minQty)
			buyHeap.DecreaseTopQuantity(minQty)
		} else {
			break
		}
	}

	return trades
}

func main() {
	buyOrders := []Order{
		{Price: 101, Quantity: 1, PlaceTime: time.Date(2023, 1, 1, 9, 1, 0, 0, time.UTC), IsBuy: false},
		{Price: 100, Quantity: 5, PlaceTime: time.Date(2023, 1, 1, 9, 0, 0, 0, time.UTC), IsBuy: true},
		{Price: 99, Quantity: 3, PlaceTime: time.Date(2023, 1, 1, 9, 1, 0, 0, time.UTC), IsBuy: true},
	}
	sellOrders := []Order{
		{Price: 99, Quantity: 2, PlaceTime: time.Date(2023, 1, 1, 9, 0, 0, 0, time.UTC), IsBuy: false},
		{Price: 100, Quantity: 4, PlaceTime: time.Date(2023, 1, 1, 9, 1, 0, 0, time.UTC), IsBuy: false},
	}

	buyHeap := &BuyHeap{}
	sellHeap := &SellHeap{}

	heap.Init(buyHeap)
	heap.Init(sellHeap)

	for _, buyOrder := range buyOrders {
		heap.Push(buyHeap, buyOrder)
	}

	for _, sellOrder := range sellOrders {
		heap.Push(sellHeap, sellOrder)
	}

	trades := MatchOrdersWithHeap(buyHeap, sellHeap)
	for _, trade := range trades {
		fmt.Printf("Executed trade: (Price: %.2f, Qty: %.2f)\n", trade.Price, trade.Quantity)
	}
}
