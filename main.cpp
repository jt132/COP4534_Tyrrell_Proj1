#include <iostream>
#include <iomanip>
#include "fileHandling.hpp"
#include "hash.hpp"

int main() {
    std::cout << "Welcome to the most elite hashing program you've ever seen" << std::endl;
    std::cout << "And also quite possibly the slowest" << std::endl;
    FileHandling fh1;
    fh1.createRaw();
    fh1.createEncrypted();
    HashTable ht1(100000);
    ht1.createTable();
    ht1.findHash("Smith");
    ht1.isMatch("Smith", "veorhdyai", "vignere");

    // Tries to open raw.txt
    std::ifstream inputFile("raw.txt");

    std::ofstream outputFile("output.txt");
    outputFile << "Legal:\n" << "UserID      " << "Password   " <<"Attempted" << "  Result" << std::endl;

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
}