package main

type IListener interface {
	update()
	OnClick(f func()) IListener
}

type SingleClickListener struct {
	funcLogic func()
}

type LongClickListener struct {
	funcLogic func()
}

func NewSingleClickListener() IListener {
	return &SingleClickListener{}
}

func NewLongClickListener() IListener {
	return &LongClickListener{}
}

func (l *SingleClickListener) OnClick(f func()) IListener {
	l.funcLogic = f

	return l
}

func (l *SingleClickListener) update() {
	l.funcLogic()
}

func (l *LongClickListener) OnClick(f func()) IListener {
	l.funcLogic = f

	return l
}

func (l *LongClickListener) update() {
	l.funcLogic()
}
