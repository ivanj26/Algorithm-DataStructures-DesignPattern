import java.util.ArrayList;
import java.util.List;

class Node<K, V> {
    Node<K, V> next;
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
        this.size = 2000;
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
            while (node.next != null && !key.equals(node.key)) {
                node = node.next;
            }

            if (key.equals(node.key)) {
                node.val = value;
            } else {
                if (node.next == null) {
                    node.next = new Node<K, V>(key, value);
                    keys.add(key);
                }
            }
        }
    }

    public void remove(K key) {
        int hashKey = this.hash(key);
        Node<K, V> node = this.buckets[hashKey];

        if (node != null) {
            if (key.equals(node.key)) { // if head of linkedlist is null
                this.buckets[hashKey] = null;
                keys.remove(key);

                return;
            }

            Node<K, V> prev = null;
            while (node != null && !key.equals(node.key)) {
                prev = node;
                node = node.next;
            }

            if (node != null) {
                if (key.equals(node.key)) {
                    if (prev != null) {
                        prev.next = node.next;
                    }
                }
            }
        }
    }

    public V get(K key) {
        int hashKey = this.hash(key);
        Node<K, V> node = this.buckets[hashKey];

        if (node == null) {
            return null;
        }

        while (node != null && !key.equals(node.key)) {
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
        
        int n = 1000000;
        for (int i = 0; i < n; i++) {
            map.put(String.valueOf(i), "value" + i);
        }

        List<String> keys = map.keys();
        int j = 0;

        // - check if is there any missing key?
        for (String key : keys) {
            if (Integer.valueOf(key) != j) {
                System.out.println("Incorrect key");
                return;
            }
            j++;
        }

        // - check if is there any missing value?
        for (int i = 0; i < n; i++) {
            String value = map.get(String.valueOf(i));

            if (!value.equals("value" + i)) {
                System.out.println("Incorrect val");
            }
        }
    }
}