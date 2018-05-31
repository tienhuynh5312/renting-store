#include "database.h"
#include "comedy.h"
#include "classics.h"
#include "drama.h"

#include <iostream>
#include <memory>
#include <regex>
#include <sstream>

bool Database::readTransaction(const std::string &command)
{
  std::smatch match;
  std::regex transPattern(R"((\w)(.*)[\r\n]*)");
  std::regex_match(command, match, transPattern);
  if (match.size() == 0)
  {
    return false;
  }

  const std::string &option = match.str(1);
  if (option == "B")
  {
    // Borrow
    borrowVideo(command);
  }
  else if (option == "R")
  {
    // Return
    returnVideo(command);
  }
  else if (option == "I")
  {
    // Display Inventory
    displayInventory();
  }
  else if (option == "H")
  {
    // Display item of a customer
    displayCustomerInfo(command);
  }
  else
  {
    // Invalid option. Notify
    std::cout << "[Error] Invalid Command: " << option << std::endl;
  }
}

bool Database::readCustomer(const std::string &command)
{
  std::smatch match;
  std::regex idPattern(R"((\d{4}) (\w*) (\w*)[\r\n]*)");
  std::regex_match(command, match, idPattern);
  if (match.size() != 4)
  {
    std::cout << "[Error] Customer Format is invalid: " << command << std::endl;
    return false;
  }
  else
  {
    int id = std::stoi(match.str(1));
    std::string first = match.str(2);
    std::string last = match.str(3);
    return addCustomer(std::make_shared<Customer>(first, last, id));
  }
}

bool Database::readVideo(const std::string &command)
{
  std::smatch match;
  // std::regex classicsPattern(R"((.+) (\d+) (\d+))");
  std::regex pattern(R"(([A-Z]), (\d+), (.+), (.+), ([\w| ]+)[\r\n]*)");
  std::regex_match(command, match, pattern);

  if (match.size() != 6)
  {
    std::cout << "[Error]: Video Format is invalid" << command << std::endl;
    return false;
  }
  else
  {
    int stock = std::stoi(match.str(2));
    std::string director{match.str(3)};
    std::string title{match.str(4)};
    if (match.str(1) == "F")
    {
      // Comedy
      Date year{std::stoi(match.str(5))};
      return addVideo(std::make_shared<Comedy>(title, stock, director, year));
    }
    else if (match.str(1) == "D")
    {
      // Drama
      Date year{std::stoi(match.str(5))};
      return addVideo(std::make_shared<Drama>(title, stock, director, year));
    }
    else if (match.str(1) == "C")
    {
      // Classics
      std::smatch last;
      std::string l{match.str(5)};
      std::regex lastPart(R"(([\w ]+) (\d+) (\d+)[\r\n]*)");
      std::regex_match(l, last, lastPart);

      if (last.size() != 4)
      {
        return false;
      }
      else
      {
        int month = std::stoi(last.str(2));
        int year = std::stoi(last.str(3));
        std::string majorActor{last.str(1)};
        return addVideo(std::make_shared<Classics>(title, stock, director, majorActor, Date(year, month)));
      }
    }
    else
    {
      return false;
    }
  }
}

bool Database::borrowVideo(const std::string &command)
{
  std::regex pattern(R"((\w) (\d{4}) (\w{1}) (\w{1})(.*)[\r\n]*)");
  std::smatch match;
  std::regex_match(command, match, pattern);
  if (match.size() != 6)
    return false;
  else
  {
    const int customerID = std::stoi(match.str(2));
    std::string itemType{match.str(3)};
    std::string videoType{match.str(4)};
    std::shared_ptr<Customer> borrower = getCustomer(customerID);

    if (borrower.get() == nullptr)
    {
      std::cout << "[Abort] Customer ID not found: " << customerID << std::endl;
      return false;
    }

    bool isSucceed = false;
    if (videoType == "F")
      isSucceed = getComedy(command);
    else if (videoType == "D")
      isSucceed = getDrama(command);
    else if (videoType == "C")
      isSucceed = getClassics(command);
    if (isSucceed)
    {
      std::shared_ptr<Transaction> trans = std::make_shared<Transaction>(command);
      transactions.add(Hashable::getHash(command), trans);
      borrower->linkTransaction(trans);
      return true;
    }
    else
      return false;
  }
}

bool Database::returnVideo(const std::string &command)
{
  return borrowVideo(command);
}

void Database::displayCustomerInfo(const std::string &command)
{
  std::regex pattern(R"((\w) (\d{4})[\r\n]*)");
  std::smatch match;
  std::regex_match(command, match, pattern);
  if (match.size() != 3)
    return;
  else
  {
    const int customerID = std::stoi(match.str(2));
    std::shared_ptr<Customer> borrower = getCustomer(customerID);
    if (borrower != nullptr)
    {
      std::cout << *borrower << std::endl;
    }
  }
}

void Database::displayInventory()
{ // shared_ptr to items
  std::cout << "=================Display Inventory=====================" << std::endl;
  auto hash_table = items.getStructure();
  const int size = items.getCapacity();
  // create buf
  std::stringstream classic;
  std::stringstream comedy;
  std::stringstream drama;
  // get structure
  for (int i = 0; i < size; i++)
  { // if empty do nothing
    if (!hash_table[i].empty())
    {
      for (auto it = hash_table[i].begin(); it != hash_table[i].end(); it++)
      {
        if (it->second->getVideoType() == std::string("Classics"))
        {
          auto shared_classic = dynamic_pointer_cast<Classics>(it->second);
          classic << *(shared_classic) << std::endl;
        }
        else if (it->second->getVideoType() == std::string("Comedy"))
        {
          comedy << *(it->second) << std::endl;
        }
        else if (it->second->getVideoType() == std::string("Drama"))
        {
          drama << *(it->second) << std::endl;
        }
      }
    }
  }
  // print all items in  string buffs
  std::cout << comedy.str() << std::endl;
  std::cout << drama.str() << std::endl;
  std::cout << classic.str() << std::endl;
  std::cout << "=================End of Inventory=====================" << std::endl;
}

bool Database::getClassics(const std::string &command)
{
  std::regex pattern(R"((\w) (\d{4}) (\w{1}) (\w{1}) (\d*) (\d*) (.*)[\r\n]*)");
  std::smatch match;
  std::regex_match(command, match, pattern);

  if (match.size() != 8)
  {
    return false;
  }
  else
  {
    const int month = std::stoi(match.str(5));
    const int year = std::stoi(match.str(6));

    const Date date{year, month};
    std::string majorActor{match.str(7)};

    const int key = Classics("", 0, "", majorActor, Date(year, month)).getHash();
    auto it = items.contains(key);
    if (it != nullptr)
    {
      if (match.str(1) == "B")
        return it->borrowItem();
      else if (match.str(1) == "R")
        return it->returnItem();
    }
    else
      return false;
  }
}

bool Database::getComedy(const std::string &command)
{
  std::regex pattern(R"((\w) (\d{4}) (\w{1}) (\w{1}) ([\w ]*), (\d*)[\r\n]*)");
  std::smatch match;
  std::regex_match(command, match, pattern);

  if (match.size() != 7)
    return false;
  else
  {
    const std::string title = match.str(5);
    const int year = std::stoi(match.str(6));
    const Date date{year};

    const int key = Comedy(title, 0, "", date).getHash();
    auto it = items.contains(key);
    if (it != nullptr)
    {
      if (match.str(1) == "B")
        return it->borrowItem();
      else if (match.str(1) == "R")
        return it->returnItem();
    }
    else
      return false;
  }
}

bool Database::getDrama(const std::string &command)
{
  std::regex pattern(R"((\w) (\d{4}) (\w) (\w) (.*), (.*),[\r\n]*)");
  std::smatch match;
  std::regex_match(command, match, pattern);
  if (match.size() != 7)
    return false;
  else
  {
    const std::string director = match.str(5);
    const std::string title = match.str(6);

    const int key = Drama(title, 0, director).getHash();
    auto it = items.contains(key);
    if (it != nullptr)
    {
      if (match.str(1) == "B")
        return it->borrowItem();
      else if (match.str(1) == "R")
        return it->returnItem();
    }
    else
      return false;
  }
}

////////////////////////////////////
std::shared_ptr<Customer> Database::getCustomer(const int &id)
{
  return customers.contains(id);
}

std::shared_ptr<Customer> Database::getCustomer(const Customer &customer)
{
  return getCustomer(customer.getCustomerID());
}

bool Database::addCustomer(std::shared_ptr<Customer> customer)
{
  if (customers.contains(customer->getCustomerID()).get() != nullptr)
    return false;
  else
    return customers.add(customer->getCustomerID(), customer);
}

bool Database::removeCustomer(const int &id)
{
  return customers.remove(id);
}

////////////////////////////////////

std::shared_ptr<Video> Database::getVideo(const int &id)
{
  return items.contains(id);
}

std::shared_ptr<Video> Database::getVideo(const Video &video)
{
  return items.contains(video.getHash());
}

bool Database::addVideo(std::shared_ptr<Video> video)
{
  if (items.contains(video->getHash()).get() != nullptr)
    return false;
  else
    return items.add(video->getHash(), video);
}

bool Database::removeVideo(const int &id)
{
  return items.remove(id);
}

std::shared_ptr<Transaction> Database::getTransaction(const std::string &transactionDetail)
{
  return getTransaction(Transaction(transactionDetail));
}

std::shared_ptr<Transaction> Database::getTransaction(const Transaction &transaction)
{
  return transactions.contains(transaction.getHash());
}

bool Database::addTransaction(std::shared_ptr<Transaction> trans)
{
  return transactions.add(trans->getHash(), trans);
}

bool Database::removeTransaction(const std::string &transactionDetail)
{
  return transactions.remove(Transaction(transactionDetail).getHash());
}
