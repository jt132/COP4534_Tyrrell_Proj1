#ifndef HASHTABLE
#define HASHTABLE
#include <functional>
#include <iostream>
#include <fstream>
#include "list.hpp"

class HashTable{
    private: 
        int size;
        List* buckets;
    public:
        HashTable (int size);
        void createTable();
        std::string findHash(std::string userID);
        std::string isMatch(std::string, std::string, std::string);
        void printTable();
};


#endif