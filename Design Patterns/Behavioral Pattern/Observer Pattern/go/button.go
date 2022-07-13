package main

import (
	"reflect"
)

type IButton interface {
	RegisterListener(l IListener)
	UnregisterListener(string)
	NotifyAll()
}

type Button struct {
	Listeners map[string]IListener
}

func NewButton() Button {
	return Button{
		Listeners: make(map[string]IListener, 0),
	}
}

func (b *Button) RegisterListener(l IListener) {
	key := reflect.
		ValueOf(l).
		Elem().
		FieldByName("Name")
	if !key.IsZero() {
		b.Listeners[key.String()] = l
	}
}

func (b *Button) UnregisterListener(key string) {
	_, found := b.Listeners[key]

	if found {
		delete(b.Listeners, key)
	}
}

func (b *Button) NotifyAll() {
	for _, listener := range b.Listeners {
		listener.update()
	}
}
