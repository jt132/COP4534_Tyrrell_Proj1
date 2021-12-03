#include <iostream>
#include "passserver.hpp"
#include "hashtable.hpp"
using namespace std;

int main()
{

    string username = "";
    string password = "";
    string newPassword = "";
    PassServer passServer;
    char choice = ' ';
    do
    {
        cout << "a - Add User" << endl;
        cout << "r - Remove User" << endl;
        cout << "c - Change User Password" << endl;
        cout << "e - Check Existence of a User" << endl;
        cout << "v - Validate Password for a User" << endl;
        cout << "n - Number of Users" << endl;
        cout << "x - Exit Program" << endl
             << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 'a':
            cout << "Please enter a username: " << endl;
            cin >> username;
            cout << "Please enter a password: " << endl;
            cin >> password;
            if (passServer.AddUser(username, password))
            {
                cout << "Successfully added the user " << username << endl;
            }
            else
            {
                cout << "Could not add the user" << username << endl;
            }
            break;
        case 'r':
            cout << "Please enter a username: " << endl;
            cin >> username;
            if (passServer.RemoveUser(username))
            {
                cout << "Successfully removed " << username << endl;
            }
            else 
            {
                cout << "Failed to remove " << username << endl;
            }
            break;
        case 'c':
            cout << "Please enter a username: " << endl;
            cin >> username;
            cout << "Please enter the current password: " << endl;
            cin >> password;
            cout << "Please enter a new password: " << endl;
            cin >> newPassword;
            if (passServer.UpdatePassword(username, password, newPassword)){
                cout << "Successfully updated the user password for " << username << endl;
            }
            else
            {
                cout << "Failed to update the user password for " << username << endl;
            }
            break;
        case 'e':
            cout << "Please enter a username: " << endl;
            cin >> username;
            if (passServer.HasUser(username)){
                cout << "Successfully found the user " << username << endl;
            }
            else
            {
                cout << "Failed to find the user " << username << endl;
            }
            break;
        case 'v':
            cout << "Please enter a username: " << endl;
            cin >> username;
            cout << "Please enter a new password: " << endl;
            cin >> password;
            if (passServer.Validate(username, password))
            {
                cout << "Succeeded in validating the user " << username << endl;
            }
            else
            {
                cout << "Failed to validate the user " << username << endl;
            }
            break;
        case 'n':
            cout << "The current number of users is " << passServer.GetSize() << endl;
            break;
        case 'x':
            cout << "This program will now end, thank you for using!" << endl;
            break;
        default:
            cout << "Uh-oh! It looks like you entered some invalid character." << endl
            << " Please be more careful in following instructions!!!!" << endl;
            break;
        }
    } while (choice != 'x');
}