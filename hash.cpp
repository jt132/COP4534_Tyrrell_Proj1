#include "hash.hpp"
#include <iostream>
#include <string>

HashTable::HashTable(int size){
    this->size = size;
    buckets = new List[size];
}

void HashTable::createTable(){
    std::ifstream readFile;
    std::ofstream writeFile;
    readFile.open("encrypted_test.txt");
    writeFile.open("hash_test.txt");

    std::string userID = "";
    std::string password = "";
    Node* temp;
    int hashNumber = 0;
    std::hash<std::string> myHashingObject;

    while(true){
        readFile >> userID >> password;
        temp = new Node(userID);
        temp->setPassword(password);

        hashNumber = myHashingObject(userID) % size;

        if(readFile.eof()){
            break;
        }

        writeFile << hashNumber << std::endl;  

        buckets[hashNumber].add(temp);
   }
}