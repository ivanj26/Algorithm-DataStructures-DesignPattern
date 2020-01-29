#include "keyhash.hpp"
#include "hashnode.hpp"

#define DEFAULT_TABLE_SIZE 20

template <typename K, typename V, typename F = KeyHash<K, DEFAULT_TABLE_SIZE>>
class HashMap {
    private:
        HashNode<K, V> **table;
        F function;
        size_t size;
    public:
        HashMap();
        ~HashMap();
        void put(K key, V val);
        void remove(K key) const throw();
        V get(K key) const throw();
};