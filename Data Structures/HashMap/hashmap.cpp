#include <iostream>
#include <stdexcept>

#include "hashmap.hpp"

template <typename K, typename V, typename F>
HashMap<K, V, F>::HashMap()
{
	size = function.size;

	table = new HashNode<K, V> *[size]();
}

template <typename K, typename V, typename F>
HashMap<K, V, F>::~HashMap()
{
	for (int i = 0; i < size; i++)
	{
		HashNode<K, V> *entry = table[i];
		HashNode<K, V> *temp = nullptr;

		while (entry != nullptr)
		{
			temp = entry;
			entry = entry->getNext();

			delete temp;
		}
	}

	delete[] table;
}

template <typename K, typename V, typename F>
void HashMap<K, V, F>::put(K key, V value)
{
	unsigned long hashValue = function(key);

	HashNode<K, V> *entry = table[hashValue];
	HashNode<K, V> *prev = nullptr;

	while (entry != nullptr && entry->getKey() != key)
	{
		prev = entry;
		entry = entry->getNext();
	}

	if (entry == nullptr)
	{
		entry = new HashNode<K, V>(key, value);

		if (prev != nullptr)
		{
			prev->setNext(entry);
		}
		else
		{
			// set as first entry
			table[hashValue] = entry;
		}
	}
	else
	{
		// update value
		entry->setValue(value);
	}
}

template <typename K, typename V, typename F>
void HashMap<K, V, F>::remove(K key) throw()
{
	unsigned long hashValue = function(key);

	HashNode<K, V> *entry = table[hashValue];
	HashNode<K, V> *prev = nullptr;

	while (entry != nullptr && entry->getKey() != key)
	{
		prev = entry;
		entry = entry->getNext();
	}

	if (entry == nullptr)
	{
		throw std::invalid_argument("Element with specified key is not found");
	}
	else
	{
		if (prev != nullptr)
		{
			HashNode<K, V> *next = entry->getNext();
			prev->setNext(next);
		}
		else
		{
			table[hashValue] = entry->getNext();
			delete prev;
		}

		delete entry;
	}
}

template <typename K, typename V, typename F>
V HashMap<K, V, F>::get(K key) const throw()
{
	unsigned long hashValue = function(key);

	HashNode<K, V> *entry = table[hashValue];
	while (entry != nullptr && entry->getKey() != key)
	{
		entry = entry->getNext();
	}

	if (entry == nullptr)
	{
		throw std::invalid_argument("Element with specified key is not found!");
	}

	return entry->getValue();
}

template <typename K, typename V, typename F>
std::vector<K> HashMap<K, V, F>::keys() const
{
	std::vector<K> keys;

	for (size_t i = 0; i < size; i++)
	{
		HashNode<K, V> *entry = table[i];

		while (entry != nullptr)
		{
			keys.push_back(entry->getKey());
			entry = entry->getNext();
		}
	}

	return keys;
}

template <class K, class V, class F>
V HashMap<K, V, F>::operator[](K k) const throw()
{
	return this->get(k);
}

template <typename K, size_t TABLE_SIZE = 10>
struct KeyHashFunc
{
	size_t size = TABLE_SIZE;
	unsigned long operator()(const K &key) const
	{
		return static_cast<unsigned long>(key) % size;
	}
};

int main(int argc, char const *argv[])
{
	HashMap<int, std::string, KeyHashFunc<int, 20> > map;
	map.put(1, "Hello");
	map.put(2, "World!");

	map.remove(3);

	std::vector<int> keys = map.keys();
	for (int i = 0; i < keys.size(); i++)
	{
		std::cout << keys[i] << " " << map[keys[i]] << std::endl;
	}

	return 0;
}
