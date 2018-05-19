/**
 * @brief Test
 * Please go to this link for how-to use Catch for test
 * https://github.com/catchorg/Catch2/blob/master/docs/tutorial.md#top
 * @file test.cpp
 * @author Tien Huynh
 * @date 2018-05-17
 */
#define CATCH_CONFIG_MAIN
#include "catch.cpp"
#include <iostream>
#include "../source/person.h"
#include "../source/customer.h"
#include "../source/hashable.h"
#include "../source/item.h"
#include "../source/video.h"
#include "../source/transaction.h"

using namespace std;

TEST_CASE("BASE DESIGN", "[design]")
{
  SECTION("Person class")
  {
    Person a("Tien", "Huynh");

    REQUIRE(a.getFirstName() == "Tien");
    REQUIRE(a.getLastName() == "Huynh");

    a.setFirstName("B");
    a.setLastName("K");

    REQUIRE(a.getFirstName() == "B");
    REQUIRE(a.getLastName() == "K");
  }

  SECTION("Customer class")
  {
    Customer a("Tien", "Huynh", 1111);
    Customer b("B","K",1112);
    Customer c("Eric","M",1131);

    REQUIRE(a.getFirstName() == "Tien");
    REQUIRE(a.getLastName() == "Huynh");

    a.setFirstName("B");
    a.setLastName("K");

    REQUIRE(a.getFirstName() == "B");
    REQUIRE(a.getLastName() == "K");

    REQUIRE(a.getCustomerID() == 1111);
    REQUIRE(a.getTotalCustomers() == 3);
  }

  SECTION("Hashable")
  {
    REQUIRE(Item("Video").getHash() == 0);
    REQUIRE(Transaction("123").getHash() == 0);
    REQUIRE(Customer("Tien","Huynh", 1234).getHash() == 0);
    REQUIRE(Hashable<int>::getHash(123) == 1480);
    REQUIRE(Hashable<int>::getHash("Tien Huynh") == 956);
  }
}