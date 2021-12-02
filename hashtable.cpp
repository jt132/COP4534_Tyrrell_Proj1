#include "hashtable.hpp"
#include <iostream>
#include <string>

template <typename K, typename V>
HashTable<K, V>::HashTable() : capacity(101), size(0) {}

template <typename K, typename V>
HashTable<K, V>::HashTable(int _capacity) : capacity(_capacity), size(0) {}

template <typename K, typename V>
int HashTable<K, V>::Hash(K key)
{
    int index = std::hash<K>{}(key) % capacity;
    return index;
}

template <typename K, typename V>
bool HashTable<K, V>::HasKey(K key)
{

    if (buckets.size() == 0)
    {
        return false;
    }
    for (int i = 0; i < buckets.size(); i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            if (key == buckets[i][j].first)
            {
                return true;
            }
        }
    }
    return false;
}

template <typename K, typename V>
bool HashTable<K, V>::Insert(K key, V value)
{

      if (HasKey(key) == true)
    {
        return false;
    }

    std::vector<std::pair<K, V>> innerVec;
    innerVec.push_back(std::make_pair(key, value));
    buckets.push_back(innerVec);

    size++;
    if (size > capacity)
    {
        return false;
    }

    return true;
}

template <typename K, typename V>
bool HashTable<K, V>::Remove(K key)
{
    if (HasKey(key) == false)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < buckets.size(); i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (key == buckets[i][j].first)
                {
                    buckets.erase(buckets.begin() + i);
                    size--;
                }
            }
        }
    }
    return true;
}

template <typename K, typename V>
void HashTable<K, V>::PrintTable()
{
    for (int i = 0; i < buckets.size(); i++)
    {
            for (int j = 0; j < buckets[i].size(); j++)
            {
                std::cout << "the key is " << buckets[i][j].first << std::endl;
                std::cout << "the value is " << buckets[i][j].second << std::endl;
            }
    }
    std::cout << size << std::endl;
}

template <typename K, typename V>
bool HashTable<K, V>::Exist(K key, V value)
{
    for (int i = 0; i < buckets.size(); i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (key == buckets[i][j].first && value == buckets[i][j].second)
            {
                return true;
            }
        }
    }
    return false;
}

template <typename K, typename V>
void HashTable<K, V>::Clear()
{
    for (int i = 0; i < buckets.size(); i++)
    {
        for (int j = 0; j < size; j++)
        {
                buckets.erase(buckets.begin() + i);
        }
    }
    size = 0; 
}

template <typename K, typename V>
void HashTable<K, V>::Resize(int capacity)
{
    this->capacity = capacity;
    this->size = 0;
}

template <typename K, typename V>
int HashTable<K, V>::GetSize()
{
    return size;
}

template <typename K, typename V>
int HashTable<K, V>::GetCapacity()
{
    return capacity;
}

template class HashTable<std::string, std::string>;
