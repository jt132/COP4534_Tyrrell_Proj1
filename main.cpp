/***************************************************************
  Student Name: Joshua Tyrrell
  File Name: main.cpp
  Assignment number: Project01

This file exists to be run as an executable and drive the program along
***************************************************************/

#include <iostream>
#include <iomanip>
#include "fileHandling.hpp"
#include "hashtable.hpp"

// This project seeks to create a simple hash table for password management
int main()
{
    std::cout << "Welcome to the most elite hashing program you've ever seen" << std::endl;
    std::cout << "Sadly, there is a segfault in here :(" << std::endl;
    FileHandling fh1;
    fh1.createRaw();
    std::cout << "Created raw.txt" << std::endl;
    fh1.createEncrypted();
    std::cout << "Created encrypted.txt" << std::endl;
    HashTable ht1(100000);
    ht1.createTable();

    // opens raw.txt
    std::ifstream inputFile("raw.txt");

    std::cout << "Valid Attempts:\n\n"
              << "UserID      "
              << "Password   "
              << "Attempted"
              << "  Result" << std::endl;

    // Loops 5 times and checks to see if it is a valid password attempt
    std::string userID, password;
    for (int i = 0; i < 5; i++)
    {
        inputFile >> userID >> password;
        std::cout << std::setw(15) << std::left << userID << password
                  << "    " << password << "    " << ht1.isMatch(userID, password, "vignere") << std::endl;
    }

    std::cout << std::endl
              << "Invalid Attempts:\n\n"
              << "UserID      "
              << "Password   "
              << "Attempted"
              << "  Result" << std::endl;

    // Loops 5 times with the wrong password and checks to see if it gets rejected
    inputFile.clear();
    inputFile.seekg(0);
    for (int i = 0; i < 5; i++)
    {
        inputFile >> userID >> password;
        std::cout << std::setw(15) << std::left << userID << password;

        if (password[0] != 'a')
            password[0] = 'a';
        else
            password[0] = 'b';

        std::cout << "  " << password << "  " << ht1.isMatch(userID, password, "vignere") << std::endl;
    }
}