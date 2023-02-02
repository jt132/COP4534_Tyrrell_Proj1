#include "vignere.hpp"

std::string Vignere::encryptPassword(std::string passwordToEncrypt, std::string keyword)
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