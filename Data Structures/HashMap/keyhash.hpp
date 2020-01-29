#include <cstddef>

template <typename K, size_t TABLE_SIZE>
struct KeyHash {
    unsigned long operator() (const K& key) const {
        return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
    }
};