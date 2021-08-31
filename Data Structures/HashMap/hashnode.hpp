template <typename K, typename V>
class HashNode
{
	private:
		K key;
		V value;
		HashNode<K, V> *next;

	public:
		HashNode(K _key, V _value) : key(_key), value(_value)
		{
		}

		HashNode<K, V> *getNext() const
		{
			return next;
		}

		void setNext(HashNode<K, V> *node)
		{
			this->next = node;
		}

		void setKey(K k)
		{
			this->key = k;
		}

		void setValue(V v)
		{
			this->value = v;
		}

		K getKey() const
		{
			return this->key;
		}

		V getValue() const
		{
			return this->value;
		}
};