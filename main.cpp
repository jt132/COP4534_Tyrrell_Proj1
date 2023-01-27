#include <iostream>
#include "user.hpp"

int main() {
    std::cout << "are we even running this program" << std::endl;
    User user1;
    //user1.readData("lastNames.txt", "raw.txt");
    //user1.readRawFile();
    std::ofstream test("test.txt", std::ios::app);
    test << user1.encryptPassword("test", "vignere");

}