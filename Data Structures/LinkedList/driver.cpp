#include "singlylinkedlist.cpp"

template <typename T>
SinglyLinkedList<T> addTwoLinkedList(SinglyLinkedList<T> *list1, SinglyLinkedList<T> *list2)
{
	SinglyNode<int> *first = list1->front();
	SinglyNode<int> *second = list2->front();
	SinglyNode<int> *temp, *prev, *resultan = nullptr;
	int carry = 0, sum;

	while (first != nullptr || second != nullptr)
	{
		sum = carry + (first ? first->getData() : 0) + (second ? second->getData() : 0);

		// update carry
		carry = (sum >= 10) ? 1 : 0;

		// update sum
		sum = sum % 10;

		// create a new node
		temp = new SinglyNode<int>(sum);

		if (resultan == nullptr)
		{
			resultan = temp;
		}
		else
		{
			prev->setNext(temp);
		}

		prev = temp;

		if (first)
		{
			first = first->getNext();
		}

		if (second)
		{
			second = second->getNext();
		}
	}

	delete first;
	delete second;

	if (carry > 0)
		temp->setNext(new SinglyNode<int>(carry));

	return SinglyLinkedList<int>(resultan);
}

int main(int argc, char const *argv[])
{
	SinglyLinkedList<int> list1;
	SinglyLinkedList<int> list2;

	// list1= 0->1->2->3->4
	for (int i = 0; i < 5; i++)
	{
		list1.push(i);
	}

	// list2= 5->4->3->2->1->0
	for (int i = 5; i >= 0; i--)
	{
		list2.push(i);
	}

	SinglyLinkedList<int> listRes = addTwoLinkedList(&list1, &list2);
	listRes.printNthToLast(0);

	return 0;
}
