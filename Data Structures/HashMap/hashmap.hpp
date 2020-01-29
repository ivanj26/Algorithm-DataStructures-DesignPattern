#include "keyhash.hpp"
#include "hashnode.hpp"

template <typename K, typename V, size_t TABLE_SIZE, typename F = KeyHash<K, TABLE_SIZE>>
class HashMap {
    private:
        HashNode<K, V> **table;
        F function;
    public:
        HashMap() {
        }
};