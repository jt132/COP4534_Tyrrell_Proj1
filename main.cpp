#include <iostream>
#include "fileHandling.hpp"
#include "hash.hpp"

int main() {
    std::cout << "Welcome to the most elite hashing program you've ever seen" << std::endl;
    std::cout << "And also quite possibly the slowest" << std::endl;
    FileHandling fh1;
    //fh1.createRaw();
    //fh1.createEncrypted();
    HashTable ht1(200);
    ht1.createTable();
}