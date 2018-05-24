
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

/*
  These following operations are needed for binary search tree to work properly.
  */
bool Transaction::operator==(const Transaction &rhs) const
{
  return transactionDetail == rhs.transactionDetail;
}

bool Transaction::operator<(const Transaction &rhs) const
{
  return transactionDetail<rhs.transactionDetail;
}

bool Transaction::operator<=(const Transaction &rhs) const
{
  return (*this < rhs) || (*this == rhs);
}

std::ostream &operator<<(std::ostream &out, const Transaction &rhs)
{
  return out << rhs.transactionDetail;
}

// end