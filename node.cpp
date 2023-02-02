#include "node.hpp"

Node::Node(){
    userID = "";
    password = "";
    next = nullptr;
}

Node::Node(std::string userID){
    this->userID = userID;
    password = "";
    next = nullptr;
}

std::string Node::getUserID(){
    return userID;
}

void Node::setUserID(std::string userID){
    this->userID = userID;
}

std::string Node::getPassword(){
    return password;
}

void Node::setPassword(std::string password){
    this->password = password;
}

void Node::setNext(Node* next){
    this->next = next;
}

Node* Node::getNext(){
    return next;
}