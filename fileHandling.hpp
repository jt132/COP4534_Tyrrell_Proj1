#ifndef FILEHANDLING
#define FILEHANDLING
#include <cstdlib>
#include <iostream> 
#include <string>
#include <fstream>

class FileHandling
{
public:
    void createRaw();
    void createEncrypted();
    std::string generatePasswords(std::string userID);
    std::string encryptPassword(std::string passwordToEncrypt, std::string keyword);
    void writeData(std::string dataToWrite, std::string filename);
};

#endif