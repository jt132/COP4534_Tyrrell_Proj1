#include <iostream>
#include <iomanip>
#include "fileHandling.hpp"
#include "hash.hpp"

int main() {
    std::cout << "Welcome to the most elite hashing program you've ever seen" << std::endl;
    std::cout << "And also quite possibly the slowest" << std::endl;
    FileHandling fh1;
    //fh1.createRaw();
    std::cout << "Created raw" << std::endl;
    //fh1.createEncrypted();
    std::cout << "Craeted encrypted" << std::endl;
    HashTable ht1(1000);
    ht1.createTable();
    std::cout << "created hash table" << std::endl;
    std::cout << "the desired hash is " << ht1.findHash("Smith");
    ht1.isMatch("Smith", "veorhdyai", "vignere");

    // Tries to open raw.txt
    std::ifstream inputFile("raw.txt");
    if(!inputFile.is_open()) {
        std::cout << "Could not open raw.txt" << std::endl;
        return 0;
    }

    std::ofstream outputFile;
    outputFile.open("output.txt");
    outputFile << "Legal:\n" << "UserID      " << "Password   " <<"Attempted" << "  Result" << std::endl;
/*
    // Loops 5 times and checks if password from raw.txt matches the password in the table
    std::string name, pass;
    for(int i = 0; i < 5; i++) {
        inputFile >> name >> pass;
        outputFile << std::setw(12) << std::left << name << pass 
                  << "  " << pass << "  " << ht1.isMatch(name, pass, "jones") << std::endl;
    }

    outputFile << std::endl << "Illegal:\n" << "UserID      " << "Password   " <<"Attempted" << "  Result" << std::endl;

    // Loops 5 times and enters the wrong password to make sure the hash table recognizes it is not a match
    inputFile.clear();
    inputFile.seekg(0);
    for(int i = 0; i < 5; i++) {
        inputFile >> name >> pass;
        outputFile << std::setw(12) << std::left << name << pass;

        if(pass[0] != 'x')
            pass[0] = 'x';
        else
            pass[0] = 'y';

        outputFile << "  " << pass << "  " << ht1.isMatch(name, pass, "jones") << std::endl;
    }
    */
}