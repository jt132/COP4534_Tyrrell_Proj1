#ifndef USER
#define USER
#include <string>
#include <fstream>

class User
{
private:
    std::string userID = "";
    std::string clearPass = "";
    std::string encryptPass = "";

public:
    User();
    std::string getUserID();
    //void createFile(std::string filename);
    std::string generatePasswords();
    void readRawFile();
    void readData(std::string readFilename, std::string writeFilename);
    void writeData(std::string dataToWrite, std::string filename);
    std::string encryptPassword(std::string passwordToEncrypt, std::string keyword);
};

#endif