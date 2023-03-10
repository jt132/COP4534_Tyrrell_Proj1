#ifndef FILEHANDLING
#define FILEHANDLING
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "vignere.hpp"

class FileHandling
{
public:
    int PASS_SIZE;
    FileHandling();
    void createRaw();
    void createEncrypted();
    std::string generatePasswords(std::string userID);
    void writeData(std::string dataToWrite, std::string filename);
};

#endif