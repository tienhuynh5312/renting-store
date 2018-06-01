#ifndef _DATABASE_H
#define _DATABASE_H
#include "hashtree.h"
#include "video.h"
#include "customer.h"
#include "transaction.h"
#include "processtext.h"
#include <string>
#include <memory>
#include <list>
#include <set>
class Database : public ProcessText
{
public:
  Database(){};
  virtual ~Database(){};

  std::shared_ptr<Customer> getCustomer(const int &id);
  std::shared_ptr<Customer> getCustomer(const Customer &customer);
  bool addCustomer(std::shared_ptr<Customer> customer);
  bool removeCustomer(const int &id);

  std::shared_ptr<Video> getVideo(const int &id);
  std::shared_ptr<Video> getVideo(const Video &video);
  bool addVideo(std::shared_ptr<Video> video);
  bool removeVideo(const int &id);

  std::shared_ptr<Transaction> getTransaction(const std::string &transactionDetail);
  std::shared_ptr<Transaction> getTransaction(const Transaction &transaction);
  bool addTransaction(std::shared_ptr<Transaction> trans);
  bool removeTransaction(const std::string &transactionDetail);

  bool readTransaction(const std::string &command);
  bool readCustomer(const std::string &command);
  bool readVideo(const std::string &command);

private:
  HashTree<int, std::shared_ptr<Customer>> customers;
  HashTree<int, std::shared_ptr<Video>> items{100};
  HashTree<int, std::shared_ptr<Transaction>> transactions{100};

  bool borrowVideo(const std::string &command);
  bool getClassics(const std::string &command);
  bool getComedy(const std::string &command);
  bool getDrama(const std::string &command);
  bool returnVideo(const std::string &command);
  void displayCustomerInfo(const std::string &command);
  void displayInventory() const;
};
#endif // !_DATABASE_H