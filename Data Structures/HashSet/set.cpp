#include "../LinkedList/singlylinkedlist.cpp"

template <class T>
class Set
{
	private:
		SinglyLinkedList<T> **bucket;
		int bucketSize = 100000;
		int hashFunc(T key)
		{
			return key % bucketSize;
		}

	public:
		/**
		 * @brief Construct a new Set object
		 * 
		 */
		Set()
		{
			bucket = new SinglyLinkedList<T> *[bucketSize];
			for (int i = 0; i < this->bucketSize; i++)
			{
				bucket[i] = nullptr;
			}
		}

		/**
		 * @brief Push new key into Set object.
		 * 
		 * @param key 
		 */
		void add(T key)
		{
			int mod = this->hashFunc(key);
			SinglyLinkedList<T> *list = this->bucket[mod];

			if (!list)
			{
				this->bucket[mod] = new SinglyLinkedList<T>(key);
			}
			else
			{
				SinglyNode<T> *curr = list->front();

				while (curr->getNext())
				{
					if (curr->getData() == key)
					{
						return;
					}

					curr = curr->getNext();
				}

				if (curr)
				{
					SinglyNode<T> *node = new SinglyNode<T>(key);
					curr->setNext(node);
				}
			}
		}

		/**
		 * @brief Remove the key from Set object.
		 * 
		 * @param key 
		 */
		void remove(T key)
		{
			int mod = this->hashFunc(key);
			SinglyLinkedList<T> *list = this->bucket[mod];

			if (list)
			{
				SinglyNode<T> *curr = list->front();
				SinglyNode<T> *prev = nullptr;

				while (curr && curr->getData() != key)
				{
					prev = curr;
					curr = curr->getNext();
				}

				if (curr && curr->getData() == key)
				{
					if (prev)
					{
						prev->setNext(curr->getNext());
					}

					if (curr == list->front())
					{
						this->bucket[mod] = new SinglyLinkedList<T>(curr->getNext());

						delete curr;
					}
					else
					{
						delete curr;
					}
				}
			}
		}

		/**
		 * @brief Returns true if this set contains the key
		 * 
		 * @param key 
		 * @return bool true|false
		 */
		bool contains(T key)
		{
			int mod = this->hashFunc(key);
			SinglyLinkedList<T> *list = this->bucket[mod];

			if (list)
			{
				SinglyNode<T> *curr = list->front();
				while (curr)
				{
					if (curr->getData() == key)
						return true;
					curr = curr->getNext();
				}
			}

			return false;
		}
};