#include <iostream>
#include <cstdlib>

using namespace std;

enum {
    EQ = 0,
    RIM,
    OP,
    ID,
    WS
};

template<typename K, typename V>
class HashNode {
public:
    V value;
    K key;

    HashNode(K key, V value) {
        this->value = value;
        this->key = key;
    }
};

template<typename K, typename V>

class HashMap {
    HashNode<K, V> **arr;
    int capacity;
    int size;
    HashNode<K, V> *dummy;

public:
    HashMap() {
        capacity = 20;
        size = 0;
        arr = new HashNode<K, V> *[capacity];

        for (int i = 0; i < capacity; i++)
            arr[i] = NULL;
        dummy = new HashNode<K, V>("-1", -1);
    }

    int hashCode(K key) {
        int total(0);
        int i(0);
        while (key[i] != '\0') {
            total += key[i];
            ++i;
        }
        return total % capacity;
    }

    void insertNode(K key, V value) {
        HashNode<K, V> *temp = new HashNode<K, V>(key, value);
        int hashIndex = hashCode(key);
        while (arr[hashIndex] != NULL && arr[hashIndex]->key != key
               && arr[hashIndex]->key != "-1") {
            hashIndex++;
            hashIndex %= capacity;
        }
        if (arr[hashIndex] == NULL || arr[hashIndex]->key == "-1")
            size++;
        arr[hashIndex] = temp;
    }


    V deleteNode(K key) {
        int hashIndex = hashCode(key);
        while (arr[hashIndex] != NULL) {
            if (arr[hashIndex]->key == key) {
                HashNode<K, V> *temp = arr[hashIndex];
                arr[hashIndex] = dummy;
                size--;
                return temp->value;
            }
            hashIndex++;
            hashIndex %= capacity;
        }
        return NULL;
    }

    V get(K key) {
        int hashIndex = hashCode(key);
        while (arr[hashIndex] != NULL) {
            if (arr[hashIndex]->key == key)
                return arr[hashIndex]->value;
            hashIndex++;
            hashIndex %= capacity;
        }
        return -1;
    }

    int sizeofMap() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }
    
    void display() {
        for (int i = 0; i < capacity; i++) {
            if (arr[i] != NULL && arr[i]->key != "-1")
                cout << "key = " << arr[i]->key
                     << "  value = " << arr[i]->value << endl;
        }
    }
};
/*
int main() {
    HashMap<string, int> *h = new HashMap<string, int>;
    h->insertNode("IF", 3);
    h->insertNode("THEN", 2);
    h->insertNode("ELSE", 1);
    h->insertNode("FOR", 0);
    h->display();

    cout << h->get("ELSE") << endl;

    return 0;
}*/