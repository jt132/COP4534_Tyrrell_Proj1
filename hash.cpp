#include "hash.hpp"
#include <iostream>
#include <string>

//default constructor
template <typename K, typename V>
HashTable<K, V>::HashTable();

//paramaterized constructor
template <typename K, typename V>
HashTable<K, V>::HashTable (int capacity);


template <typename K, typename V>
void HashTable<K, V>::fillVector();

template <typename K, typename V>
int HashTable<K, V>::hash(K key);

template <typename K, typename V>
bool HashTable<K, V>::hasKey( K key);

template <typename K, typename V>
bool insert(K key, V value);

template <typename K, typename V>
bool HashTable<K, V>::doesExist(K key, V value);

template <typename K, typename V>
bool HashTable<K, V>::remove (K key);

template <typename K, typename V>
void HashTable<K, V>::clear();

template <typename K, typename V>
void HashTable<K, V>::printTable();

template class HashTable<std::string, std::string>;

