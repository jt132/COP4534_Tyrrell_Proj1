/***************************************************************
  Student Name: Joshua Tyrrell
  File Name: hashtable.cpp
  Assignment number: Project01

This file exists to handle the hashtable
***************************************************************/
#include "hashtable.hpp"
#include <iostream>
#include <string>

// creates hash table object that accepts whatever size is desired from main
HashTable::HashTable(int size)
{
    this->size = size;
    buckets = new List[size];
}

// This function loads data into the hashtable from the encrypted text
void HashTable::createTable()
{
    std::ifstream readFile;
    readFile.open("encrypted.txt");

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
        buckets[hashNumber].add(temp);
    }
}
// this function seeks to find the hash based off of the userID
std::string HashTable::findHash(std::string userID)
{
    int hashNumber;
    std::hash<std::string> myHashingObject;
    hashNumber = myHashingObject(userID) % size;

    return buckets[hashNumber].findEntry(userID);
}

// this function checks if the given userID and password match, based off of the hashtable
// and the encrypted password created in the vignere class
std::string HashTable::isMatch(std::string userID, std::string password, std::string keyword)
{
    Vignere V;
    std::string encryptedPassword = V.encryptPassword(password, keyword);

    if (encryptedPassword == findHash(userID))
    {
        return "this is a match";
    }
    else
    {
        return "not a match";
    }
}