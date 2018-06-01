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
#include "../source/database.h"
#include "../source/comedy.h"
#include <regex>
#include <iostream>
#include <vector>
#include <memory>
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
    REQUIRE(Hashable::getHash(123) == 982);
    REQUIRE(Hashable::getHash("Tien Huynh") == 956);
  }

  SECTION("Classics")
  {
    Classics Romeo("Romeo", 10, "TH", "BK", Date(2017, 10));
    REQUIRE(Romeo.getMajorActor() == "BK");
    Classics Juliet("Romeo", 10, "TH", "BK", Date(2017, 10));
    Video &a = (Video &)Romeo;

    Video &c = dynamic_cast<Video &>(Romeo);

    REQUIRE(a.getDirector() == "TH");
    REQUIRE(c.getTotalStock() == 10);

    std::vector<std::shared_ptr<Video>> videoList;
    videoList.push_back(std::make_shared<Classics>("Romeo", 10, "TH", "BK", Date(2017)));

    auto tmp = dynamic_pointer_cast<Classics>(videoList.front());
    CHECK(tmp->getMajorActor() == "BK");
    CHECK(tmp->getDate().getYear() == 2017);
    CHECK(tmp->getTitle() == "Romeo");
    CHECK(tmp->getTotalStock() == 10);
  }

  SECTION("HashTree")
  {

    // HashTree<Customer> customerList;
    // customerList.add(Customer("Tien", "Huynh", 1111));
    // REQUIRE(customerList.contains(Customer("Tien", "Huynh", 1111)).getFirstName() == "Tien");
    // REQUIRE(customerList.contains(Customer("Tien", "Huynh", 1111)).getLastName() == "Huynh");
    // REQUIRE(customerList.contains(Customer("Tien", "Huynh", 1111)).getCustomerID() == 1111);

    // HashTree<Transaction> transactionList;
    // transactionList.add(Transaction("1234 5560"));
    // HashTree<Item> itemList;
    // itemList.add(Item("Video", 1111));
    // Classics romeo("Romeo", 10, "Tien");
    // itemList.add(romeo);

    // CHECK(itemList.contains(romeo).getCurrentStock() == 10);
    // CHECK(itemList.contains(romeo).getTotalStock() == 10);

    // HashTree<int, Customer*> list;
    // list.add(1111, new Customer(1111));

    HashTree<int, std::shared_ptr<Customer>> customerList;
    Customer me{"Tien", "Huynh", 1111};
    std::shared_ptr<Customer> t = std::make_shared<Customer>(me);
    customerList.add(1111, t);
    REQUIRE(customerList.contains(1111)->getCustomerID() == 1111);
    REQUIRE(customerList.contains(1111)->getFirstName() == "Tien");
    REQUIRE(customerList.contains(1111)->getLastName() == "Huynh");
    REQUIRE(customerList.contains(1111) == t);
    REQUIRE(customerList.contains(1112) == nullptr);
    customerList.remove(1111);
    REQUIRE(customerList.contains(1111) == nullptr);
    HashTree<int, std::shared_ptr<Transaction>> transaction;
    transaction.add(Hashable::getHash("Tien Huynh"), std::make_shared<Transaction>("Tien Huynh"));

    REQUIRE(transaction.contains(Hashable::getHash("Tien Huynh")) != nullptr);
    REQUIRE(transaction.contains(Hashable::getHash("Tien Huynh"))->getTransactionDetail() == "Tien Huynh");

    const int i = 4;
    const_cast<int &>(i) = 3;
    REQUIRE(i == 3);
  }

  SECTION("HashTree Video")
  {
    HashTree<int, std::shared_ptr<Video>> video;

    std::shared_ptr<Classics> c = std::make_shared<Classics>("TH", 10, "TH", "TH", Date(2018));
    video.add(c->getHash(), c);
    REQUIRE(video.contains(c->getHash()) == c);
    REQUIRE(video.contains(c->getHash())->getTitle() == "TH");
    REQUIRE(video.contains(c->getHash())->getCurrentStock() == 10);
    video.contains(c->getHash())->borrowItem();
    REQUIRE(video.contains(c->getHash())->getCurrentStock() == 9);

    REQUIRE(dynamic_pointer_cast<Classics>(video.contains(c->getHash()))->getMajorActor() == "TH");
  }

  SECTION("Database")
  {
    try
    {
      Database data;
      data.readFile(FileType::CUSTOMER, "data4customers.txt");
      REQUIRE(data.getCustomer(3333)->getFirstName() == "Witch");
      REQUIRE(data.getCustomer(8888)->getFirstName() == "Pig");
      REQUIRE(data.getCustomer(4444)->getFirstName() == "Moose");
      REQUIRE(data.getCustomer(9999)->getFirstName() == "Duck");
      REQUIRE(data.getCustomer(6666)->getFirstName() == "Donkey");
      REQUIRE(data.getCustomer(7777)->getFirstName() == "Spider");
      REQUIRE(data.getCustomer(1111)->getFirstName() == "Mouse");
      REQUIRE(data.getCustomer(9000)->getFirstName() == "Lizard");
      REQUIRE(data.getCustomer(8000)->getFirstName() == "Wacky");
      REQUIRE(data.getCustomer(5000)->getFirstName() == "Frog");
      REQUIRE(data.getCustomer(2000)->getFirstName() == "Duck");
      data.readFile(FileType::VIDEO, "data4movies.txt");
      data.readFile(FileType::TRANSACTION, "data4commands.txt");

      const int key = Classics("It's a Wonderful Life",10, "Frank Capra", "James Steward", Date(1946,11)).getHash();
      REQUIRE(data.getVideo(key).get() != nullptr);
      REQUIRE(data.getVideo(key)->getTotalStock() == 10);
      REQUIRE(data.getVideo(key)->getTitle() == "It's a Wonderful Life");
      REQUIRE(data.getVideo(key)->getDirector() == "Frank Capra");
      REQUIRE(dynamic_pointer_cast<Classics>(data.getVideo(key))->getMajorActor() == "James Steward");
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
  }
  // SECTION("Reading DataMovies")
  // {
  //   try
  //   {
  //     // classics movie last part pattern: (.+) (\d+) (\d+)
  //     std::smatch match;
  //     std::regex classicsPattern(R"((.+) (\d+) (\d+))");
  //     std::regex pattern(R"(([A-Z]), (\d+), (.+), (.+), ([\w| ]+))");
  //     std::string s = {"C, 10, George Cukor, Holiday, Cary Grant 9 1938"};
  //     std::regex_match(s, match, pattern);

  //     std::cout << match.size() << std::endl;
  //     for (std::size_t i = 0; i < match.size(); i++)
  //       std::cout << i << ": " << match.str(i) << std::endl;

  //     // For classics movie only
  //     if (match.str(1) == "C")
  //     {
  //       // std::string lastPart = match.str(5);
  //       // std::regex_match(lastPart, match, pattern);
  //       // std::cout << match.size() << std::endl;
  //       // for (std::size_t i = 0; i < match.size(); i++)
  //       //   std::cout << i << ": " << match.str(i) << std::endl;

  //       std::string name = match.str(5);
  //       std::regex namePattern(R"(([\w ]+) (\d) (\d+))");
  //       std::regex_match(name, match, namePattern);
  //       std::cout << match.size() << std::endl;
  //       for (std::size_t i = 0; i < match.size(); i++)
  //         std::cout << i << ": " << match.str(i) << std::endl;
  //     }

  //     // =================
  //     // ID

  //     std::regex idPattern(R"((\d{4}) (\w+) (\w+)[\r*\n*])");
  //     std::string id{"1111 Mouse Mickey\r\n"};
  //     std::regex_match(id, match, idPattern);
  //     std::cout << match.size() << std::endl;
  //     for (std::size_t i = 0; i < match.size(); i++)
  //       std::cout << i << ": " << match.str(i) << std::endl;

  //     // ===================
  //     // Transaction

  //     std::regex transPattern(R"((\w)(.*))");
  //     std::string trans{"B 1234 D C 9 1938 Katherine Hepburn"};
  //     std::regex_match(trans, match, transPattern);
  //     std::cout << match.size() << std::endl;
  //     for (std::size_t i = 0; i < match.size(); i++)
  //       std::cout << i << ": " << match.str(i) << std::endl;
  //   }
  //   catch (std::regex_error &e)
  //   {
  //     std::cout << e.what() << std::endl;
  //   }
  // }
}