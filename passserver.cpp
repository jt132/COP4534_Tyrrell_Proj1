#include "passserver.hpp"

PassServer::PassServer() : capacity(101) {}

PassServer::PassServer(int _capacity) : capacity(_capacity) {}

std::string PassServer::Hash(const std::string &password)
{
    SHA1 hashFunc;
    hashFunc.update(password);
    return hashFunc.final();
}

bool PassServer::AddUser(const std::string &username, const std::string &password)
{
    if (table.GetSize() >= capacity)
    {
        return false;
    }

    if (table.Insert(username, password))
    {
        return true;
    }
    else
        return false;
}

bool PassServer::RemoveUser(const std::string &username)
{

    if (table.Remove(username))
    {
        return true;
    }
    else
        return false;
}

bool PassServer::Validate(const std::string &username, const std::string &password)
{
    if (table.Exist(username, password))
    {
        return true;
    }
    else
        return false;
}

bool PassServer::UpdatePassword(const std::string &username, const std::string &password, const std::string &newPass)
{
    if (!table.Exist(username, password)){
        return false;
    }
    if (table.Remove(username) && table.Insert(username, newPass)){
        return true;
    }
    else
        return false;

}

bool PassServer::HasUser(const std::string &username)
{
   if (table.HasKey(username))
   {
       return true;
   } 
   else
       return false;
}

int PassServer::GetSize()
{
    return table.GetSize();
}