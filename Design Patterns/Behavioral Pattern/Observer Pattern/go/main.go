package main

import (
	"fmt"
)

func main() {
	var (
		button            = NewButton()
		listener          = NewSingleClickListener()
		longClickListener = NewLongClickListener()
	)

	button.RegisterListener(
		listener.OnClick(func() {
			fmt.Println("onClick() method triggered")
		}),
	)
	button.RegisterListener(
		longClickListener.OnClick(func() {
			fmt.Println("long click method triggered")
		}),
	)
	button.UnregisterListener(longClickListener.GetName())

	button.NotifyAll()
}
