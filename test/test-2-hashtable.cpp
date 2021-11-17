#include "catch/catch.hpp"
#include "../hashtable.hpp"
#include <string>

TEST_CASE("HasKey and exist ops")
{
	HashTable<std::string, std::string> hashTable;
	REQUIRE(!hashTable.HasKey("abc"));
	REQUIRE(!hashTable.Exist("abc", "pass"));
	REQUIRE(hashTable.Insert("abc", "pass"));
	REQUIRE(hashTable.Exist("abc", "pass"));
	REQUIRE(!hashTable.Exist("bbc", "pass"));
	REQUIRE(!hashTable.Exist("abc", "bass"));
	REQUIRE(hashTable.HasKey("abc"));
	REQUIRE(!hashTable.HasKey("bbc"));
	REQUIRE(hashTable.Remove("abc"));
	REQUIRE(!hashTable.Exist("abc", "pass"));
	REQUIRE(!hashTable.HasKey("abc"));
}

TEST_CASE("Get size ops")
{
	HashTable<std::string, std::string> hashTable;
	REQUIRE(hashTable.Insert("abc", "pass"));
	REQUIRE(1 == hashTable.GetSize());
	REQUIRE(hashTable.Insert("bbc", "pass"));
	REQUIRE(2 == hashTable.GetSize());
	REQUIRE(hashTable.Remove("abc"));
	REQUIRE(1 == hashTable.GetSize());
	REQUIRE(hashTable.Remove("bbc"));
	REQUIRE(0 == hashTable.GetSize());
}

TEST_CASE("Clear ops")
{
	HashTable<std::string, std::string> hashTable;
	REQUIRE(hashTable.Insert("abc", "pass"));
	REQUIRE(hashTable.HasKey("abc"));
	REQUIRE(hashTable.Insert("bbc", "pass"));
	REQUIRE(hashTable.HasKey("bbc"));
	REQUIRE(2 == hashTable.GetSize());
	hashTable.Clear();
	REQUIRE(0 == hashTable.GetSize());
	REQUIRE(!hashTable.HasKey("abc"));
	REQUIRE(!hashTable.HasKey("bbc"));
}
