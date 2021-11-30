#include "hashtable.hpp"
#include <iostream>
#include <string>

template <typename K, typename V>
HashTable<K, V>::HashTable() : capacity(101), size(0){}

template <typename K, typename V>
bool HashTable<K, V>::HasUser(K key, V value){
    return false;
}

template <typename K, typename V>
bool HashTable<K, V>::HasKey (K key){
    return false;
}

template <typename K, typename V>
bool HashTable<K, V>::Insert(K key, V value){
    return false;
}

template <typename K, typename V>
bool HashTable<K, V>::Remove (K key){
    return false;
}

template <typename K, typename V>
void HashTable<K, V>::Clear(){}

template <typename K, typename V>
void HashTable<K, V>::Resize (int capacity){
    capacity = capacity;
}

template <typename K, typename V>
int HashTable<K, V>::GetSize(){
    return size;
}

template <typename K, typename V>
int HashTable<K, V>::GetCapacity(){
    return capacity;
}


template class HashTable<std::string,std::string>;

