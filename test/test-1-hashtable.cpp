#include "catch/catch.hpp"
#include "../hashtable.hpp"
#include <string>

TEST_CASE("Constructor resize get capacity and get size ops")
{
  HashTable<std::string, std::string> hashTable;
  REQUIRE(0 == hashTable.GetSize());
  REQUIRE(101 == hashTable.GetCapacity());
  hashTable.Resize(103);
  REQUIRE(0 == hashTable.GetSize());
  REQUIRE(103 == hashTable.GetCapacity());
}

// TEST_CASE("Insert ops")
// {
//   HashTable<std::string, std::string> hashTable;
//   REQUIRE(hashTable.Insert("abc", "pass"));
//   // duplicate insert will fail
//   REQUIRE(!hashTable.Insert("abc", "pass1"));
//   HashTable<std::string, std::string> hashTable1(2);
//   REQUIRE(hashTable1.Insert("abc", "pass"));
//   REQUIRE(hashTable1.Insert("bbc", "pass"));
//   // will fail because the size is going beyond the capacity
//   REQUIRE(!hashTable1.Insert("cbc", "pass"));
// }

// TEST_CASE("Remove ops")
// {
//   HashTable<std::string, std::string> hashTable;
//   REQUIRE(hashTable.Insert("abc", "pass"));
//   REQUIRE(hashTable.Insert("bbc", "pass"));
//   REQUIRE(hashTable.Remove("abc"));
//   REQUIRE(!hashTable.Remove("abc"));
//   REQUIRE(!hashTable.Remove("aaa"));
//   REQUIRE(hashTable.Remove("bbc"));
// }

// TEST_CASE("Resize")
// {
//   HashTable<std::string, std::string> hashTable;
//   REQUIRE(hashTable.Insert("abc", "pass"));
//   REQUIRE(hashTable.Insert("bbc", "pass"));
//   REQUIRE(2 == hashTable.GetSize());
//   REQUIRE(101 == hashTable.GetCapacity());
//   hashTable.Resize(5);
//   REQUIRE(0 == hashTable.GetSize());
//   REQUIRE(5 == hashTable.GetCapacity());
// }
