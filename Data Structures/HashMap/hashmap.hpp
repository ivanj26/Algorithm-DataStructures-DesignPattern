#include <vector>
#include "hashnode.hpp"
#include <vector>

template <typename K, typename V, typename F>
class HashMap {
    private:
        HashNode<K, V> **table;
        F function;
        size_t size;
    public:
        HashMap();
        ~HashMap();
        void put(K, V);
        void remove(K) throw();
        V get(K) const throw();
        std::vector<K> keys() const;
        V operator[](K k) const throw();
};