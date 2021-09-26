#include <iostream>
using namespace std;

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

			while (curr && curr->key != key)
			{
				curr = curr->next;
			}

			if (!curr)
			{
				this->buckets[hashKey] = new HashNode(key, value);
			}
			else
			{
				if (curr->key == key)
				{
					curr->val = value;
				}
				else
				{
					curr->next = new HashNode(key, value);
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

int main(int argc, char const *argv[])
{
	HashMap map;
	map.put(1, 3);
	map.put(2, 2);
	map.put(1, 4);
	cout << map.get(1) << endl;

	map.remove(1);

	cout << map.get(1) << endl;
	cout << map.get(2) << endl;
	cout << map.get(3) << endl;

	map.put(1, 5);

	cout << map.get(1) << endl;
	return 0;
}
