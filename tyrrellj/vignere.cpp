/***************************************************************
  Student Name: Joshua Tyrrell
  File Name: vignere.cpp
  Assignment number: Project01

This file exists to create encryption that the passwords require
***************************************************************/

#include "vignere.hpp"

// This class is responsible for encrypting the password and only has the constructor
// and an encrypt password function, which does exactly what it sounds like
Vignere::Vignere() {}

std::string Vignere::encryptPassword(std::string passwordToEncrypt, std::string keyword)
{
    std::string encryptedPassword = "";

    for (int i = 0, j = 0; i < passwordToEncrypt.size(); i++, j++)
    {
        char c = ((passwordToEncrypt[i] + keyword[j]) % 26);
        if (j == (keyword.length() - 1))
        {
            j = 0;
        }

        c += 'a';

        encryptedPassword.push_back(c);
    }
    return encryptedPassword;
}