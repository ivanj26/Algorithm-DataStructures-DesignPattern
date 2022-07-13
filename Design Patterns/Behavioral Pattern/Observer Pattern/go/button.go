package main

import (
	"bytes"
	"encoding/gob"
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

func hash(l IListener) string {
	var b bytes.Buffer

	gob.NewEncoder(&b).Encode(l)
	return b.String()
}

func (b *Button) RegisterListener(l IListener) {
	b.Listeners[hash(l)] = l
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
