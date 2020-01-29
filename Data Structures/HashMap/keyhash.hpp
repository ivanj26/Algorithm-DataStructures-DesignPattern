#include <cstddef>

template <typename K, size_t TABLE_SIZE>
struct KeyHash {
    size_t size = TABLE_SIZE;
    unsigned long operator() (const K& key) const {
        return static_cast<unsigned long>(key) % TABLE_SIZE;
    }
};