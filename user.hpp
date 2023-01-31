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
    void createRaw();
    void createEncrypted();
    std::string generatePasswords();
    std::string encryptPassword(std::string passwordToEncrypt, std::string keyword);
    void writeData(std::string dataToWrite, std::string filename);
};

#endif