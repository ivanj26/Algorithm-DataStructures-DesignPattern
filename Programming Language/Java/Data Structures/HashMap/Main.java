import java.util.ArrayList;
import java.util.List;

class Node<K, V> {
    Node next;
    V val;
    K key;

    Node(K _key, V _val) {
        this.key = _key;
        this.val = _val;
        this.next = null;
    }
}

class HashMap<K, V> {
    private Node<K, V>[] buckets;
    private List<K> keys;
    private int size;

    private int hash(K k) {
        return k.hashCode() % size;
    }

    public HashMap() {
        this.size = 100000;
        this.buckets = new Node[size];
        this.keys = new ArrayList<K>();
    }

    public void put(K key, V value) {
        int hashKey = this.hash(key);
        Node<K, V> node = buckets[hashKey];

        if (node == null) {
            this.buckets[hashKey] = new Node<K, V>(key, value);
            keys.add(key);
        } else {
            while (node.next != null && node.key != key) {
                node = node.next;
            }

            if (node.next == null) {
                node.next = new Node<K, V>(key, value);
                keys.add(key);
            }

            if (node.key == key) {
                node.val = value;
            }
        }
    }

    public void remove(K key) {
        int hashKey = this.hash(key);
        Node<K, V> node = this.buckets[hashKey];

        if (node != null) {
            if (node == this.buckets[hashKey]) { // if head of linkedlist is null
                this.buckets[hashKey] = null;
                keys.remove(key);

                return;
            }

            Node<K, V> prev = null;
            while (node != null && node.key != key) {
                prev = node;
                node = node.next;
            }

            if (node.key == key) {
                prev.next = node.next;
            }
        }
    }

    public V get(K key) {
        int hashKey = this.hash(key);
        Node<K, V> node = buckets[hashKey];

        if (node == null) {
            return null;
        }

        while (node != null && node.key != key) {
            node = node.next;
        }

        return node != null ? node.val : null;
    }

    public List<K> keys() {
        return this.keys;
    }
}

public class Main {
    public static void main(String[] args) {
        HashMap<String, String> map = new HashMap<String, String>();
        map.put("budi", "test");
        map.put("bude", "ya");
        map.put("buda", "ok");

        map.remove("bude");

        List<String> keys = map.keys();
        for (String key : keys) {
            System.out.printf("Key: %s\n", key);
        }
    }
}