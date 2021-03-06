/**
 * File   : singlynode.cpp
 * Author : Ivan Jonathan
 **/

#include <iostream>

using namespace std;

template <class T>
class SinglyNode
{
	private:
		T data;
		SinglyNode<T> *next;

	public:
		SinglyNode(T _data) : data(_data), next(nullptr)
		{
		}

		T getData() { return data; }
		void setData(T data)
		{
			this->data = data;
		}

		SinglyNode<T> *getNext()
		{
			return next;
		}
		void setNext(T _next)
		{
			next = new SinglyNode(_next);
		}

		void setNext(SinglyNode<T> *_next) { next = _next; }
};