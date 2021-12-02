#ifndef PASSSERVER
#define PASSSERVER
#include "hashtable.hpp"
#include "sha1.hpp"


//template <typename K, typename V>
class PassServer{
    private:
        HashTable<std::string, std::string> table;
        int capacity;
    public:
        std::string Hash(const std::string &password);
        PassServer();
        PassServer(int _capacity);
        bool AddUser(const std::string &username, const std::string &password);
        bool RemoveUser(const std::string &username);
        bool Validate(const std::string &username, const std::string &password);
        bool UpdatePassword(const std::string &username, const std::string &password, const std::string &newPass);
        bool HasUser(const std::string &username);
        int GetSize();
};

#endif