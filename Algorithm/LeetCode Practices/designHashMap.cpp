struct HashNode
{
	HashNode *next;
	int key;
	int val;
	HashNode(int key, int val)
	{
		this->key = key;
		this->val = val;
		this->next = nullptr;
	}
};

class HashMap
{
	private:
		HashNode **buckets;
		int bucketSize;
		int hashFunc(int key)
		{
			return key % this->bucketSize;
		}

	public:
		HashMap() : bucketSize(100000)
		{
			buckets = new HashNode *[bucketSize];
			for (int i = 0; i < this->bucketSize; i++)
			{
				buckets[i] = nullptr;
			}
		}

		void put(int key, int value)
		{
			int hashKey = this->hashFunc(key);
			HashNode *curr = this->buckets[hashKey];
			HashNode *prev = nullptr;

			while (curr && curr->key != key)
			{
				prev = curr;
				curr = curr->next;
			}

			if (!curr)
			{
				if (prev)
				{
					curr = prev;
					curr->next = new HashNode(key, value);
				}
				else
				{
					this->buckets[hashKey] = new HashNode(key, value);
				}
			}
			else
			{
				if (curr->key == key)
				{
					curr->val = value;
				}
			}
		}

		void remove(int key)
		{
			int hashKey = this->hashFunc(key);
			HashNode *curr = this->buckets[hashKey];
			HashNode *prev = nullptr;

			while (curr && curr->key != key)
			{
				prev = curr;
				curr = curr->next;
			}

			if (curr)
			{
				if (curr == this->buckets[hashKey])
				{
					this->buckets[hashKey] = curr->next;
				}

				if (prev)
				{
					prev->next = curr->next;
				}

				delete curr;
			}
		}

		int get(int key)
		{
			int hashKey = this->hashFunc(key);
			HashNode *curr = this->buckets[hashKey];

			while (curr && curr->key != key)
			{
				curr = curr->next;
			}

			return !curr ? -1 : curr->val;
		}
};