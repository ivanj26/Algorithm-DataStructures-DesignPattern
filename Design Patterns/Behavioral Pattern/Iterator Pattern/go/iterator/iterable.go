package main

type iterable interface {
	Next() *Book
	HasNext() bool
}

type BookIterator struct {
	iterable
	current int
	books   []Book
}

type BookContainer struct {
	iterator BookIterator
}

func NewBookContainer(collection []Book) *BookContainer {
	return &BookContainer{
		iterator: BookIterator{
			current: 0,
			books:   collection,
		},
	}
}

func (c *BookContainer) GetIterator() *BookIterator {
	return &c.iterator
}

func (i *BookIterator) Next() *Book {
	if i.HasNext() {
		book := i.books[i.current]
		i.current++

		return &book
	}

	return nil
}

func (i *BookIterator) HasNext() bool {
	return i.current < len(i.books)
}
