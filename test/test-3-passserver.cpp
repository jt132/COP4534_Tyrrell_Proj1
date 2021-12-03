#include "catch/catch.hpp"
#include "../passserver.hpp"
#include <string>

using namespace std;

TEST_CASE("Add users")
{
  PassServer passServer;
  REQUIRE(passServer.AddUser("bjohn", "123"));
  // duplicate add should fail
  REQUIRE(!passServer.AddUser("bjohn", "111"));
  REQUIRE(passServer.AddUser("clynn", "123"));
  PassServer passServer1(2);
  REQUIRE(passServer1.AddUser("bjohn", "123"));
  REQUIRE(passServer1.AddUser("clynn", "123"));
  // fail because beyond capacity
  REQUIRE(!passServer1.AddUser("jsmith", "123"));
}

TEST_CASE("Remove users")
{
  PassServer passServer;
  REQUIRE(passServer.AddUser("bjohn", "123"));
  REQUIRE(passServer.RemoveUser("bjohn"));
  REQUIRE(!passServer.RemoveUser("notexist"));
}

TEST_CASE("Validate users")
{
  PassServer passServer;
  REQUIRE(passServer.AddUser("bjohn", "123"));
  REQUIRE(passServer.Validate("bjohn", "123"));
  // wrong password
  REQUIRE(!passServer.Validate("bjohn", "111"));
  // user not exist
  REQUIRE(!passServer.Validate("ajohn", "111"));
}

TEST_CASE("Check existence of users")
{
  PassServer passServer;
  REQUIRE(!passServer.HasUser("bjohn"));
  REQUIRE(passServer.AddUser("bjohn", "123"));
  REQUIRE(passServer.HasUser("bjohn"));
  REQUIRE(passServer.RemoveUser("bjohn"));
  REQUIRE(!passServer.HasUser("bjohn"));
  // other non-exist user
  REQUIRE(!passServer.HasUser("ajohn"));
}

TEST_CASE("Update passwords for users")
{
  PassServer passServer;
  REQUIRE(passServer.AddUser("bjohn", "123"));
  REQUIRE(passServer.Validate("bjohn", "123"));
  // fail with wrong password
  REQUIRE(!passServer.UpdatePassword("bjohn", "111", "123"));
  // fail with wrong username
  REQUIRE(!passServer.UpdatePassword("ajohn", "123", "111"));
  REQUIRE(passServer.UpdatePassword("bjohn", "123", "111"));
//   // password changed
  REQUIRE(passServer.Validate("bjohn", "111"));
}
