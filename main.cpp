#include <iostream>
#include "user.hpp"

int main() {
    std::cout << "Welcome to the most elite hashing program you've ever seen" << std::endl;
    std::cout << "And also quite possibly the slowest" << std::endl;
    User user1;
    user1.createRaw();
    user1.createEncrypted();
}