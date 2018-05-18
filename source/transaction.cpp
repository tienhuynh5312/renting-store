
#include <string>

#include "transaction.h"
// private 
// protected
// public
Transaction::Transaction(const std::string &detail)
  : transactionDetail(detail)
{

}

Transaction::~Transaction()
{

}

const std::string &Transaction::getTransactionDetail() const
{
  return this->transactionDetail;
}

const int Transaction::Hashable::getHash() const
{
  return 0;
}