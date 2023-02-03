#ifndef NODE
#define NODE
#include <string>

class Node
{
private:
    std::string userID;
    std::string password;
    Node *next;

public:
    Node();
    Node(std::string userID);
    std::string getUserID();
    void setUserID(std::string userID);
    std::string getPassword();
    void setPassword(std::string password);
    void setNext(Node *next);
    Node *getNext();
};

#endif