struct SinglyLinkedListNode
{
	int data;
	SinglyLinkedListNode *next;
};

int findMergePoint(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
	SinglyLinkedListNode *currentA = head1;
	SinglyLinkedListNode *currentB = head2;

	while (currentA != currentB)
	{
		//If you reached the end of one list start at the beginning of the other one
		//currentA
		if (currentA->next == nullptr)
		{
			currentA = head2;
		}
		else
		{
			currentA = currentA->next;
		}
		//currentB
		if (currentB->next == nullptr)
		{
			currentB = head1;
		}
		else
		{
			currentB = currentB->next;
		}
	}

	return currentB->data;
}