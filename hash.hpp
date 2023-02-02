#ifndef HASHTABLE
#define HASHTABLE
#include <vector>
#include <functional>

template <typename K, typename V>
class HashTable{
    private: 
        int capacity;
        int size;
        std::vector<std::vector<std::pair<K, V>>> buckets;
    public:
        HashTable();
        HashTable (int capacity);
        void fillVector();
        int hash(K key);
        bool hasKey( K key):
        bool insert(K key, V value);
        bool doesExist(K key, V value);
        bool remove (K key);
        void clear();
        void printTable();
};


#endif