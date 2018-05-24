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

  std::shared_ptr<Customer> getCustomer(const int &id);
  std::shared_ptr<Customer> getCustomer(const Customer &customer);
  bool addCustomer(const Customer &customer);
  bool removeCustomer(const int &id);

  std::shared_ptr<Customer> getVideo(const int &id);
  std::shared_ptr<Customer> getVideo(const Video &video);
  bool addVideo(const Video &video);
  bool removeVideo(const int &id);

  std::shared_ptr<Transaction> &getTransaction(const std::string &transactionDetail);
  std::shared_ptr<Transaction> &getTransaction(const Transaction &transaction);
  bool addTransaction(const Transaction &transaction);
  bool removeTransaction(const std::string &transactionDetail);

private:
  HashTree<int, std::shared_ptr<Customer>> customers;
  HashTree<int, std::shared_ptr<Video>> items;
  HashTree<int, std::shared_ptr<Transaction>> transactions;

  bool readTransaction(const std::string &command);
  bool readCustomer(const std::string &command);
  bool readVideo(const std::string &command);
};
#endif // !_DATABASE_H