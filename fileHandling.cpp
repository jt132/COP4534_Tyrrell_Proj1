#include "fileHandling.hpp"

void FileHandling::createRaw()
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
        myText = myText + "     " + generatePasswords(myText);
        writeData(myText, "raw.txt");
    }
    readFile.close();
}

void FileHandling::createEncrypted()
{
    Vignere V;
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
        encryptedPassword = V.encryptPassword(passwordToEncrypt, "vignere");
        myText = myText + "    " + encryptedPassword; 
        writeData(myText, "encrypted.txt");
    }
}

std::string FileHandling::generatePasswords(std::string userID)
{
    srand(time(0));
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                        'h', 'i', 'j', 'k', 'l', 'm', 'n',
                        'o', 'p', 'q', 'r', 's', 't', 'u',
                        'v', 'w', 'x', 'y', 'z'};
    std::string clearPassword = "";
  
    for (int i = 0, j = 0; i < 9; i++, j++)
    {
        if (j == (userID.length()-1)){
            j = 0;
        }
        clearPassword = clearPassword + letters[(std::rand() + userID[j]) % 26];
    }
    return clearPassword;
}

void FileHandling::writeData(std::string dataToWrite, std::string filename)
{
    std::ofstream MyFile(filename, std::ios::app);
    MyFile << dataToWrite << std::endl;
}

