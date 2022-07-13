package main

import "fmt"

type IListener interface {
	update()
	GetName() string
	OnClick(f func()) IListener
}

type ListenerType int

const (
	SingleClickListenerType = iota
	LongClickListenerType
)

type SingleClickListener struct {
	Name      string
	funcLogic func()
}

type LongClickListener struct {
	Name      string
	funcLogic func()
}

func NewSingleClickListener() IListener {
	return &SingleClickListener{
		Name: fmt.Sprint(SingleClickListenerType),
	}
}

func NewLongClickListener() IListener {
	return &LongClickListener{
		Name: fmt.Sprint(LongClickListenerType),
	}
}

func (l *SingleClickListener) OnClick(f func()) IListener {
	l.funcLogic = f

	return l
}

func (l *SingleClickListener) GetName() string {
	return l.Name
}

func (l *SingleClickListener) update() {
	l.funcLogic()
}

func (l *LongClickListener) OnClick(f func()) IListener {
	l.funcLogic = f

	return l
}

func (l *LongClickListener) GetName() string {
	return l.Name
}

func (l *LongClickListener) update() {
	l.funcLogic()
}
