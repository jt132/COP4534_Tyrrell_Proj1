#ifndef LIST
#define LIST
#include "node.hpp"

class List
{
private:
    Node *head;

public:
    List();
    void add(Node *user);
    //std::string findEntry(std::string userID);
    std::string findEntry(std::string userID, Node* node);
};

#endif