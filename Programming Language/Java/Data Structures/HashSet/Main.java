import java.util.ArrayList;

class Node<V> {
	V value;
	Node<V> next;

	Node(V _value) {
		this.value = _value;
		this.next = null;
	}
}

class HashSet<V> {
	private Node<V>[] buckets;
	private int size;
	private ArrayList<V> keys;

	private int hash(V key) {
		return key.hashCode() % this.size;
	}

	public HashSet() {
		this.size = 2000;
		this.keys = new ArrayList<>();
		this.buckets = new Node[this.size];
	}

	public void add(V value) {
		int hashKey = this.hash(value);
		Node<V> node = this.buckets[hashKey];

		if (node == null) {
			this.buckets[hashKey] = new Node<V>(value);
			keys.add(value);
		} else {
			boolean isFound = false;
			while (node.next != null && !isFound) {
				if (node.value.equals(value)) {
					isFound = true;
				} else {
					node = node.next;
				}
			}

			if (!isFound) {
				node.next = new Node<V>(value);
				keys.add(value);
			}
		}
	}

	public void remove(V value) {
		int hashKey = this.hash(value);
		Node<V> node = this.buckets[hashKey];
		Node<V> prev = null;

		while (node != null && !node.value.equals(value)) {
			prev = node;
			node = node.next;
		}

		if (node != null) {
			if (node == this.buckets[hashKey]) {
				this.buckets[hashKey] = node.next;
				return;
			}

			if (prev != null) {
				prev.next = node.next;
			}
		}
	}

	public boolean exist(V value) {
		int hashKey = this.hash(value);
		Node<V> node = this.buckets[hashKey];

		if (node == null) {
			return false;
		}

		if (node.value.equals(value)) {
			return true;
		}

		while (node != null && !node.value.equals(value)) {
			node = node.next;
		}

		return node != null ? true : false;
	}

	public ArrayList<V> keys() {
		return this.keys;
	}
}

public class Main {
	public static void main(String[] args) {
		HashSet<String> set = new HashSet<String>();

		set.add("12345");
		set.add("123456");
		set.add("123457");
		set.add("123458");
		set.add("123459");

		set.remove("123457");

		for (String key : set.keys()) {
			System.out.printf("is %s exist\t: %b\n", key, set.exist(key));
		}
	}
}
