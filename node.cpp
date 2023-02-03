#include "node.hpp"

// This constructor creates nodes. These nodes are the users
Node::Node()
{
    userID = "";
    password = "";
    next = nullptr;
}

// This is a paramaterized constructor which allows for the specific userID to be input
Node::Node(std::string userID)
{
    this->userID = userID;
    password = "";
    next = nullptr;
}

// Getter function for the userID
std::string Node::getUserID()
{
    return userID;
}
// Setter function for the userID
void Node::setUserID(std::string userID)
{
    this->userID = userID;
}

// Getter function for the password
std::string Node::getPassword()
{
    return password;
}
// Setter function for the password
void Node::setPassword(std::string password)
{
    this->password = password;
}

// Getter function for the node
Node *Node::getNext()
{
    return next;
}

// Seter function for the node
void Node::setNext(Node *next)
{
    this->next = next;
}
