template<typename K, typename V>
class HashNode {
    private:
        K _key;
        V _value;
        HashNode<K, V>* _next;

        HashNode(const HashNode&);
        HashNode& operator=(const HashNode&);
    public:
        HashNode(const K &key, const V &value) : _value(value), _key(key)
        {
        }
        
        K getKey() const {
            return _key;
        }

        V getValue() const {
            return _value;
        }

        HashNode<K, V>* getNext() const {
            return _next;
        }

        void setKey(const K &key) {
            _key = key;
        }

        void setValue(const V &value) {
            _value = value;
        }

        void setNext(HashNode *next) {
            _next = next;
        }
};