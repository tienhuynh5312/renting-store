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
#include "../source/customer.h"
#include "../source/person.h"
#include "../source/item.h"
#include "../source/video.h"
#include "../source/transaction.h"
#include "../source/classics.h"
#include "../source/hashable.h"
#include "../source/hashtree.h"
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
    Customer b("B", "K", 1112);
    Customer c("Eric", "M", 1131);

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
    REQUIRE(Item("Video").getHash() == 624);
    REQUIRE(Transaction("123").getHash() == 150);
    REQUIRE(Customer("Tien", "Huynh", 1234).getHash() == 8759);
    REQUIRE(Hashable<int>::getHash(123) == 982);
    REQUIRE(Hashable<int>::getHash("Tien Huynh") == 956);
  }

  SECTION("Classics")
  {
    Classics Romeo("Romeo", 10, "TH", "BK", Date(2017));
    REQUIRE(Romeo.getMajorActor() == "BK");
    Classics Juliet("Romeo", 10, "TH", "BK", Date(2017));
    Video &a = (Video &)Romeo;

    Video &c = dynamic_cast<Video &>(Romeo);

    REQUIRE(a.getDirector() == "TH");
    REQUIRE(c.getTotalStock() == 10);
  }

  SECTION("HashTree")
  {
    HashTree<Customer> itemList;
    itemList.add(Customer("Tien","Huynh",1111));
    REQUIRE(itemList.contains(Customer("Tien","Huynh",1111)).getFirstName() == "Tien");
    REQUIRE(itemList.contains(Customer("Tien","Huynh",1111)).getLastName() == "Huynh");
    REQUIRE(itemList.contains(Customer("Tien","Huynh",1111)).getCustomerID() == 1111);
  }
}