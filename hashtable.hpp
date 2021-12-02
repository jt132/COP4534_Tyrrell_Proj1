#ifndef HASHTABLE
#define HASHTABLE
#include <vector>
#include <functional>


template <typename K, typename V>
class HashTable{
    private:
        int capacity;
        int size;
        std::vector<std::vector<std::pair<K, V> > > buckets;
    public: 
        HashTable();
        HashTable(int _capacity);
        void fillVector();
        int Hash(K key);
        bool HasUser(K key, V value);
        bool HasKey (K key);
        bool Insert(K key, V value);
        bool Exist(K key, V value);
        bool Remove (K key);
        void Clear();
        void PrintTable();
        void Resize (int capacity);
        int GetCapacity();
        int GetSize();


};

#endif 