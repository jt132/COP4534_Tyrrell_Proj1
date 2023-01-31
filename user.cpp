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

void User::createRaw()
{
    std::string myText = "";
    std::ifstream readFile;
    
    remove("raw.txt");
    readFile.open("lastNames.txt");
    
    while (getline(readFile, myText))
    {
        myText = myText.substr(0, myText.find(" "));
        //maybe add a param to generatePassword function
        //the param would take the userID and multiply
        //the password char by the userID char
        //it would be way more random that way
        myText = myText + "     " + generatePasswords();
        writeData(myText, "raw.txt");
    }
    readFile.close();
}

void User::createEncrypted()
{
    std::string passwordToEncrypt = "";
    std::string encryptedPassword = "";
    std::string myText = "";
    std::ifstream readFile;

    //remove("encrypted.txt");
    readFile.open("raw.txt");
    while (getline(readFile, myText))
    {
        passwordToEncrypt = myText.substr((myText.length()-9), myText.length());
        myText = myText.substr(0, myText.find(" "));
        encryptedPassword = encryptPassword(passwordToEncrypt, "vignere");
        myText = myText + "    " + encryptedPassword; 
        writeData(myText, "encrypted.txt");
    }
}



std::string User::generatePasswords()
{
    srand(time(0));
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                        'h', 'i', 'j', 'k', 'l', 'm', 'n',
                        'o', 'p', 'q', 'r', 's', 't', 'u',
                        'v', 'w', 'x', 'y', 'z'};
    std::string clearPassword = "";

    
    for (int i = 0; i < 9; i++)
    {
        clearPassword = clearPassword + letters[std::rand() % 26];
    }
    return clearPassword;
}

std::string User::encryptPassword(std::string passwordToEncrypt, std::string keyword)
{
    std::string encryptedPassword = "";

    for (int i = 0, j = 0; i < passwordToEncrypt.size(); i++, j++){
        char c = ((passwordToEncrypt[i] + keyword[j]) % 26);
        if (j == (keyword.length()-1))
        {
            j = 0;
        }

        c += 'a';

        encryptedPassword.push_back(c);
    }
    return encryptedPassword;
}


void User::writeData(std::string dataToWrite, std::string filename)
{
    std::ofstream MyFile(filename, std::ios::app);
    MyFile << dataToWrite << std::endl;
}

