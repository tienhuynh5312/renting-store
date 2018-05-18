#define CATCH_CONFIG_MAIN
#include "catch.cpp"
#include <iostream>
#include "../source/person.h"
using namespace std;

TEST_CASE("Person","[person]")
{
  Person a("Tien","Huynh");
  
  REQUIRE(a.getFirstName() == "Tien");
  REQUIRE(a.getLastName() == "Huynh");

  a.setFirstName("B");
  a.setLastName("K");

  REQUIRE(a.getFirstName() == "B");
  REQUIRE(a.getLastName() == "K");
}