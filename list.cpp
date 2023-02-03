#include "list.hpp"

List::List(){
    head = nullptr;
}

void List::add(Node* userToPush){
    if(head == nullptr){
        head = userToPush;
    }
    else {
        userToPush->setNext(head);
        head = userToPush;
    }
}

std::string List::findEntry(std::string userID, Node* node){
    if (head == nullptr){
        return "This is an empty hash table";
    }

    if (userID == head->getUserID()){
        return head->getPassword();
    }

    if(head->getNext() == nullptr){
        return "No more items in the hash table";
    }

    return findEntry(userID, head->getNext());
}

std::string List::findEntry(std::string userID){
     if (head == nullptr){
        return "This is an empty hash table";
    }

    if (userID == head->getUserID()){
        return head->getPassword();
    }

    if(head->getNext() == nullptr){
        return "No more items in the hash table";
    }

    return findEntry(userID, head->getNext());
}
