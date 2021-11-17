# The Password Management App
[![Points badge](../../blob/badges/.github/badges/points.svg)](../../actions)

## Objective:
Develop a C++ program that uses:
- Hash table
- Password Hashing
- Templates

## Preparatory Readings:
To complete this project, you need to make sure that you have read the
following:

- Chapter: Hashing

## Project Description:
User accounts are one the most valuable assets of the giant social media
companies such as Facebook, Instagram, Youtube, etc. Fast password lookup and
managing is not trivial. In this project we will employ hashing related
algorithms and data structures to handle both fast insert/remove/lookup of
username-password pairs and secure storage of passwords.

The hash table data structure is an efficient way to provide a fast lookup
speed on average. A key-value map data structure is implemented as a hash
table. Separate chaining (aka closed-address hashing) will be employed as the
collision resolution method.

For security reasons, passwords should never be stored in their original form as
plain text. A common practice is to apply a hash function on a new password
and store the resulting hash code in the storage system. When a password needs
to be validated, the same hash function will be applied and the resulting hash
code is compared to the hash code stored in the storage system. Assuming the
extremely low collision rate of the hash function, it is an efficient way to
avoid storing passwords as plain text. To keep it simple and avoid use of
external encryption libraries, we will provide a public domain implementation of
the SHA1 hash function for experiment.

## Code Organization
### The driver
The driver as the entry point of the program is responsible for providing a
text-menu based interface to allow users to manage username and password through
an instance of the **PassServer** class. Refer to the sample runs for the details of
the text-menu.

### The PassServer Class
This class is responsible for providing password management related
functionalities. The core data structure in this class is an instance of the
HashMap class that provide efficient key-value storage. It should also take care
of the password hashing. The passwords must be encrypted in this class using the
provided [SHA1 hash function](sha1.hpp) and the hash code can then be passed to the
hash table in further operations. All usernames should not contain spaces.
This class should have the following instance variables and methods:

* `HashTable table`
    * The hash table to store the username and hashed password as a key-value map
* `std::string Hash(const std::string &password)`
    * The Hash function that encrypts the password
    * Include the sha1.hpp
    * Use the following snippet to generate the hash

        ```cpp
        SHA1 hashFunc;
        hashFunc.update(password);
        return hashFunc.final();
        ```

* `explicit PassServer(int capacity = 101)`
    * the constructor to set the value for the capacity of the password storage
* `bool AddUser(const std::string &username, const std::string &password)`
    * Adds a user with a given username and password
    * The return value indicates if the add is successful
* `bool RemoveUser(const std::string &username)`
    * Remove a user with a given username
    * The return value indicates if the removal is successful
* `bool Validate(const std::string &username, const std::string &password)`
    * Validate a user given a username and a password
    * The return value indicates if the username-password combination is present in the **HashTable**
* `bool UpdatePassword(const std::string &username, const std::string &password, const std::string &newPass)`
    * Update the password of a user given a username, an old password and a new
      password
    * The return value indicates if the update was successful
* `bool HasUser(const std::string &username)`
    * Check the existence of a username
* `int GetSize()`
    * Return the current number of username-password pairs stored in the system

### The HashTable Class Template
This is a class template that takes to types K and V to instantiate where K is
the type for key and V is the type for value. This class is implemented based on
the data structure of a vector of vectors for separate chains. The top level
vector is the buckets of the hash table and each element vector is the separate
chain for each vector. The element in the chain should be an [std::pair](https://en.cppreference.com/w/cpp/utility/pair) instance
to store key and value. This class should have the following instance variables
and methods:

* `int capacity`
    * the number of buckets to be used in a hash table, should be a prime number
* `int size`
    * the number of key-value pairs stored in the hash table
* `int Hash(K key)`
    * Use the `std::hash<K>{}(key) % capacity` expression to generate the index from a given key of the K type
    * Include the **functional** (`#include <functional>`) system header to get access to the hash function
* `std::vector<std::vector<std::pair<K, V>>> buckets`
    * the vector of buckets
* `explicit HashTable(int capacity = 101)`
    * the constructor to set the value for the capacity
* `bool HasUser(K key, V value)`
    * Check if a key-value pair is present in the hash table
    * Return true only when both key and value matches
* `bool HasKey(K key)`
    * Check if a key is present in the hash table
* `bool Insert(K key, V value)`
    * Insert a key-value pair to the hash table
    * The return value indicates if the insert was successful
    * Insert should fail if the size reached the certain threshold as a fixed fraction of the capacity for optimized
      performance, for simplicity, we set the fraction to 100% of the capacity here. Thus, size should be no more than
      the capacity
    * Insert should fail if the key already exists
* `bool Remove(K key)`
    * Remove the key-value pair from the hash table with key equal to `key`
    * The return value indicates if the delete was successful
    * Remove should return `false` if the key did not exist in the hash table
* `void Clear()`
    * Clear all key-value pairs in the hash table and reset the size
* `void Resize(int capacity)`
    * Resize the hash table to the new capacity; all existing contents should be cleared and the size reset to zero
* `int GetSize()`
    * Return the number of key-value pairs in the hash table

![UML Class diagrams](https://www.plantuml.com/plantuml/png/hLF1Ji904Btp5NCo9M8YLyG6GumQBWI4-z2TwCPbjzaT2cZuTwVGq4KQDSPBqxwPzzxkpEiWC7fUBKqhCnW2ZEKn9L-GXuyMm1KyOdXzneMXVc3LwmNsshvq8Ff8WSlwJTaUutjgaZaR-0I-oCLZxRngbvHBe4rkTAOvyawqPSWmHu6tS0lTwsxLl73Em9rIiq2-INibkCKbTU0RurXhGajNq4zoCMEEHYja-XVxMLvAZQlAdoKRYvRMfN1i9olvvLNB3JmGJ_Kx9GBjgdpKSHXrvccLaNXRHo08iuv4GHaxtpzxpr5xaO9vcgQWaF78twTd16-q_PAJ-WnDCQdlUh_HWGyAeWy5cXMrJqOneksX7i5FLkRGI8lp4jCAfnKC3Q5F8c12Ce3J4xRF1niZmwfDq5rhG5R9N_a9)

## Sample run

```
a - Add User
r - Remove User
c - Change User Password
e - Check Existence of a User
v - Validate Password for a User
n - Number of Users
x - Exit program

Enter choice : n
The current number of users is 0


a - Add User
r - Remove User
c - Change User Password
e - Check Existence of a User
v - Validate Password for a User
n - Number of Users
x - Exit program

Enter choice : a
Please enter a username:
bjohn
Please enter a new password:
12345
    Succeed to add the user bjohn


a - Add User
r - Remove User
c - Change User Password
e - Check Existence of a User
v - Validate Password for a User
n - Number of Users
x - Exit program

Enter choice : e
Please enter a username:
ajohn
    Fail to find the user ajohn


a - Add User
r - Remove User
c - Change User Password
e - Check Existence of a User
v - Validate Password for a User
n - Number of Users
x - Exit program

Enter choice : e
Please enter a username:
bjohn
    Succeed to find the user bjohn


a - Add User
r - Remove User
c - Change User Password
e - Check Existence of a User
v - Validate Password for a User
n - Number of Users
x - Exit program

Enter choice : v
Please enter a username:
bjohn
Please enter a new password:
123
    Fail to validate the user bjohn


a - Add User
r - Remove User
c - Change User Password
e - Check Existence of a User
v - Validate Password for a User
n - Number of Users
x - Exit program

Enter choice : v
Please enter a username:
ajohn
Please enter a new password:
12345
    Fail to validate the user ajohn


a - Add User
r - Remove User
c - Change User Password
e - Check Existence of a User
v - Validate Password for a User
n - Number of Users
x - Exit program

Enter choice : v
Please enter a username:
bjohn
Please enter a new password:
12345
    Succeed to validate the user bjohn


a - Add User
r - Remove User
c - Change User Password
e - Check Existence of a User
v - Validate Password for a User
n - Number of Users
x - Exit program

Enter choice : n
The current number of users is 1


a - Add User
r - Remove User
c - Change User Password
e - Check Existence of a User
v - Validate Password for a User
n - Number of Users
x - Exit program

Enter choice : c
Please enter a username:
aaa
Please enter the current password:
bbb
Please enter a new password:
bbb
    Fail to update the user password for aaa


a - Add User
r - Remove User
c - Change User Password
e - Check Existence of a User
v - Validate Password for a User
n - Number of Users
x - Exit program

Enter choice : c
Please enter a username:
bjohn
Please enter the current password:
123
Please enter a new password:
123
    Fail to update the user password for bjohn


a - Add User
r - Remove User
c - Change User Password
e - Check Existence of a User
v - Validate Password for a User
n - Number of Users
x - Exit program

Enter choice : c
Please enter a username:
bjohn
Please enter the current password:
12345
Please enter a new password:
11111
    Succeed to update the user password for bjohn


a - Add User
r - Remove User
c - Change User Password
e - Check Existence of a User
v - Validate Password for a User
n - Number of Users
x - Exit program

Enter choice : v
Please enter a username:
bjohn
Please enter a new password:
11111
    Succeed to validate the user bjohn


a - Add User
r - Remove User
c - Change User Password
e - Check Existence of a User
v - Validate Password for a User
n - Number of Users
x - Exit program

Enter choice : x
```

## Implementation Notes:
1. Create a project that is object-oriented, therefore there should be several classes.
2. The input file will match the exact format given above.

## Submission Requirements:
1. All code must be added and committed to your local git repository.
2. All code must be pushed to the GitHub repository created when you "accepted"
   the assignment.
	1. After pushing, with `git push origin main`, visit the web URL of your repository to verify that your code is there.
	   If you don't see the code there, then we can't see it either.
3. Your code must compile and run. The auto-grading tests will indicate your
   score for your submission.
	1. The auto-grading build should begin automatically when you push your code to GitHub.
	2. If your program does not compile, the graders will not be responsible for trying to test it.
	3. You should get an email regarding the status of your build, if it does not pass, keep trying.

## Important Notes:
- Projects will be graded on whether they correctly solve the problem, and whether they adhere to good programming practices.
- Projects must be received by the time specified on the due date. Projects received after that time will get a grade of zero.
- Please review the academic honesty policy.
	- Note that viewing another student's solution, whether in whole or in part, is considered academic dishonesty.
	- Also note that submitting code obtained through the Internet or other sources, whether in whole or in part, is considered academic dishonesty.
	- All programs submitted will be reviewed for evidence of academic dishonesty, and all violations will be handled accordingly.

## Breakdown of Grades:
- 70% GitHub auto-grading
- 15% Driver program
- 15% Coding style, naming, formatting class design, implementation decision, etc.

## Grading
- View on GitHub:
	1. On your GitHub repo page, Click the :arrow_forward: **Actions** tab to see your graded results.
	1. If it isn't a green check mark (:heavy_check_mark:) then at least part of the testing failed.
	1. Click the commit message for the failing version then click "Autograding" on the left side of the page.
	1. Follow the :x: path and expand things to see what errors exist.
	1. At the bottom of the _education/autograding_ section, you can view the score for the auto-grading portion of the rubric.
	   It will look something like ***40/90***.
