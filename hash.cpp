#include "hash.hpp"
#include <iostream>
#include <string>

HashTable::HashTable(int size)
{
    this->size = size;
    buckets = new List[size];
}

void HashTable::createTable()
{
    std::ifstream readFile;
    std::ofstream writeFile;
    readFile.open("encrypted_test.txt");
    writeFile.open("hash_test.txt");

    std::string userID = "";
    std::string password = "";
    Node *temp;
    int hashNumber = 0;
    std::hash<std::string> myHashingObject;

    while (true)
    {
        readFile >> userID >> password;
        temp = new Node(userID);
        temp->setPassword(password);

        hashNumber = myHashingObject(userID) % size;

        if (readFile.eof())
        {
            break;
        }

        writeFile << hashNumber << std::endl;  

        buckets[hashNumber].add(temp);
   }
}
// this function will find the hash based off of the userID
std::string HashTable::findHash(std::string userID)
{
    int hashNumber;
    std::hash<std::string> myHashingObject;
    hashNumber = myHashingObject(userID) % size;

    return buckets[hashNumber].findEntry(userID, nullptr);
}

std::string HashTable::isMatch(std::string userID, std::string password, std::string keyword)
{
    Vignere V;
    std::string encryptedPassword = V.encryptPassword(password, keyword);
    
    if (encryptedPassword == findHash(userID)){
            return "this is a match";
    }
    else{
        return "not a match";
    }
}