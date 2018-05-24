#pragma once
#ifndef _DATABASE_H
#define _DATABASE_H
#include "hashtree.h"
#include "video.h"
#include "customer.h"
#include "transaction.h"
#include "processtext.h"
#include <string>
#include <memory>
class Database : public ProcessText
{
public:
  Database();
  virtual ~Database();

  Customer &getCustomer(const int &id);
  Customer &getCustomer(const Customer &customer);
  bool addCustomer(const Customer &customer);
  bool removeCustomer(const int &id);

  Item &getVideo(const int &id);
  Item &getVideo(const Video &video);
  bool addVideo(const Video &video);
  bool removeVideo(const int &id);

  Transaction &getTransaction(const std::string &transactionDetail);
  Transaction &getTransaction(const Transaction &transaction);
  bool addTransaction(const Transaction &transaction);
  bool removeTransaction(const std::string &transactionDetail);

private:
  HashTree<int, Customer> customers;
  HashTree<int, std::shared_ptr<Video>> items;
  HashTree<int, Transaction> transactions;

  bool readTransaction(const std::string &command);
  bool readCustomer(const std::string &command);
  bool readVideo(const std::string &command);
};
#endif // !_DATABASE_H