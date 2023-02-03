/***************************************************************
  Student Name: Joshua Tyrrell
  File Name: list.cpp
  Assignment number: Project01

This file exists to create the list that the hashtable will utilize
***************************************************************/

#include "list.hpp"

// This creates the List object, which will hold a list of nodes
List::List()
{
    head = nullptr;
}

// this function adds a node to the list
void List::add(Node *userToPush)
{
    if (head == nullptr)
    {
        head = userToPush;
    }
    else
    {
        userToPush->setNext(head);
        head = userToPush;
    }
}

// this function finds the entry by recursively checking through the hash table.
// this funtion starts the recursive process
std::string List::findEntry(std::string userID, Node *node)
{
    if (head == nullptr)
    {
        return "This is an empty hash table";
    }

    if (userID == head->getUserID())
    {
        return head->getPassword();
    }

    if (head->getNext() == nullptr)
    {
        return "No more items in the hash table";
    }

    return findEntry(userID, head->getNext());
}

// this function continues the recursive process of checking through the hash table
std::string List::findEntry(std::string userID)
{
    if (head == nullptr)
    {
        return "This is an empty hash table";
    }

    if (userID == head->getUserID())
    {
        return head->getPassword();
    }

    if (head->getNext() == nullptr)
    {
        return "No more items in the hash table";
    }

    return findEntry(userID, head->getNext());
}
