/***************************************************************
  Student Name: Joshua Tyrrell
  File Name: fileHandling.cpp
  Assignment number: Project01

This file exists to handle the creation of raw.txt, encrypted.txt, and password generation
***************************************************************/

#include "fileHandling.hpp"

FileHandling::FileHandling()
{
    PASS_SIZE = 9;
}

// this function creates raw.txt based off of lastnames.txt
void FileHandling::createRaw()
{
    std::string myText = "";
    std::ifstream readFile;

    remove("raw.txt");
    readFile.open("lastNames.txt");

    while (getline(readFile, myText))
    {
        myText = myText.substr(0, myText.find(" "));
        myText = myText + "     " + generatePasswords(myText);
        writeData(myText, "raw.txt");
    }
    readFile.close();
}

// this function creates the encrypted file based off of raw.txt
void FileHandling::createEncrypted()
{
    Vignere V;
    std::string passwordToEncrypt = "";
    std::string encryptedPassword = "";
    std::string myText = "";
    std::ifstream readFile;
    readFile.open("raw.txt");
    while (getline(readFile, myText))
    {
        passwordToEncrypt = myText.substr((myText.length() - PASS_SIZE), myText.length());
        myText = myText.substr(0, myText.find(" "));
        encryptedPassword = V.encryptPassword(passwordToEncrypt, "vignere");
        myText = myText + "    " + encryptedPassword;
        writeData(myText, "encrypted.txt");
    }
    readFile.close();
}

// this function generates passwords that are used to create the raw.txt file
std::string FileHandling::generatePasswords(std::string userID)
{
    srand(time(0));
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                        'h', 'i', 'j', 'k', 'l', 'm', 'n',
                        'o', 'p', 'q', 'r', 's', 't', 'u',
                        'v', 'w', 'x', 'y', 'z'};
    std::string clearPassword = "";

    for (int i = 0, j = 0; i < PASS_SIZE; i++, j++)
    {
        if (j == (userID.length() - 1))
        {
            j = 0;
        }
        clearPassword = clearPassword + letters[(std::rand() + userID[j]) % 26];
    }
    return clearPassword;
}

// this function writes data to filenames for both the raw.txt file as well as the encrypted.txt file
void FileHandling::writeData(std::string dataToWrite, std::string filename)
{
    std::ofstream MyFile(filename, std::ios::app);
    MyFile << dataToWrite << std::endl;
}
