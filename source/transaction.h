
#ifndef _TRANSACTION_H
#define _TRANSACTION_H

#include <string>
class Transaction
{
private:
  std::string transactionDetail;
protected:
public:
  Transaction() = delete; // Do not accept empty transaction.
  Transaction(const std::string &detail);
  ~Transaction();
  std::string &getTransactionDetail() const;
};

#endif
