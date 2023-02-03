#ifndef VIGNERE
#define VIGNERE
#include <string>

class Vignere
{
public:
    Vignere();
    std::string encryptPassword(std::string passwordToEncrypt, std::string keyword);
};

#endif