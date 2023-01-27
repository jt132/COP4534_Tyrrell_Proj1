#include <cstdlib>
#include <iostream>
#include "user.hpp"

User::User()
{
    std::string userId = "";
    std::string clearPass = "";
    std::string encryptData = "";
}

std::string User::getUserID()
{
    return userID;
}

// This function is really more of a create raw.txt function
// should abstract this out
void User::readData(std::string readFilename, std::string writeFilename)
{
    std::string myText = "";
    std::ifstream readFile;

    readFile.open(readFilename);
    while (getline(readFile, myText))
    {
        myText = myText.substr(0, myText.find(" "));
        myText = myText + "     " + generatePasswords();
        writeData(myText, writeFilename);
    }

    readFile.close();
}



std::string User::generatePasswords()
{
    srand(time(0));
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                        'h', 'i', 'j', 'k', 'l', 'm', 'n',
                        'o', 'p', 'q', 'r', 's', 't', 'u',
                        'v', 'w', 'x', 'y', 'z'};
    std::string clearPassword = "";

    // 9 is a magic number...might need to change that
    for (int i = 0; i < 9; i++)
    {
        clearPassword = clearPassword + letters[std::rand() % 26];
    }
    return clearPassword;
}

void User::writeData(std::string dataToWrite, std::string filename)
{
    std::ofstream MyFile(filename, std::ios::app);
    MyFile << dataToWrite << std::endl;
}
void User::readRawFile()
{
    std::string passwordToEncrypt = "";
    std::string myText = "";
    std::ifstream readFile;

    readFile.open("raw.txt");
    while (getline(readFile, myText))
    {
        passwordToEncrypt = myText.substr((myText.length()-9), myText.length());
        myText = myText.substr(0, myText.find(" "));
        std::string encryptedPassword = encryptPassword(passwordToEncrypt, "vignere");
        myText = myText + "    " +  encryptedPassword;
        writeData(myText, "encrypted.txt");
    }
}

std::string User::encryptPassword(std::string passwordToEncrypt, std::string keyword)
{
    std::string encryptedPassword = "";
    char c = ' ';

    for (int i = 0, j = 0; i < passwordToEncrypt.size(); i++, j++){
        c = (((passwordToEncrypt[i] + keyword[j]) % 26) + 97);
        if (j == (keyword.length()-1))
        {
            j = 0;
        }
        encryptedPassword = encryptedPassword + c;
    }
    return encryptedPassword;
}
