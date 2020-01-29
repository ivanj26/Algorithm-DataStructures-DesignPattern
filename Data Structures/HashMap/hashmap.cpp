#include "./hashmap.hpp"
#include <stdexcept>

template <typename K, typename V, typename F>
HashMap<K, V, F>::HashMap() {
    size = function.size;

    //allocate entry with size in KeyHash struct
    table = new HashNode<K, V> *[size]();
}

template <typename K, typename V, typename F>
HashMap<K, V, F>::~HashMap() {
    //destroy the bucket 1 by 1
    for (size_t i = 0; i < size; i++) {
        HashNode<K, V> *entry = table[i];
        while (entry != nullptr) {
            HashNode<K, V> *prev = entry;
            entry = entry->getNext();

            delete prev;
        }
    }

    //destroy the table
    delete[] table;
}

template <typename K, typename V, typename F>
void HashMap<K, V, F>::put(K key, V value) {
    unsigned long hashValue = function(key); 
    HashNode<K, V> *entry = table[hashValue];
    HashNode<K, V> *prev = nullptr;

    //if bucket is available then iterate the entry 
    while (entry != nullptr && entry->getKey() != key) {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == nullptr) {
        entry = new HashNode<K, V>(key, value);

        //check prev
        if (prev != nullptr) {
            prev->setNext(entry);
        } else {
            //insert as first entry in bucket
            table[hashValue] = entry;
        }
    } else {
        //just update the value
        entry->setValue(value);
    }
}

template <typename K, typename V, typename F>
void HashMap<K, V, F>::remove(K key) const throw() {
    unsigned long hashValue = function(key);
    HashNode<K, V> *entry = table[hashValue];
    HashNode<K, V> *prev = nullptr;

    while (entry != nullptr && key != entry->getKey()) {
        prev = entry;
        entry = entry->getNext();
    }

    //key is not found
    if (entry == nullptr) {
        throw std::invalid_argument("Element with specified key is not found!");
    } else {
        if (prev == nullptr) {
            table[hashValue] = entry->getNext();
        } else {
            prev->setNext(entry->getNext());
        }

        delete entry;
    }
}

template <typename K, typename V, typename F>
V HashMap<K, V, F>::get(K key) const throw() {
    unsigned long hashValue = function(key);
    HashNode<K, V> *entry = table[hashValue];

    while (entry != nullptr && entry->getKey() != key) {
        entry = entry->getNext();
    }

    if (entry == nullptr) {
        throw std::invalid_argument("Element with specified key is not found");
        return nullptr;
    }

    return entry->getValue();
}

template <typename K, typename V, typename F>
vector<K> HashMap<K, V, F>::keys() const {
    vector<K> keys;

    for (size_t i = 0; i < size; i++) {
        HashNode<K, V> *entry = table[i];

        while (entry != nullptr) {
            keys.push_back(entry->getKey());
            entry = entry->getNext();
        }
    }

    return keys;
}

template<typename K, typename V, typename F>
V HashMap<K, V, F>::operator[](const K &key) const throw() {
    return this->get(key);
}