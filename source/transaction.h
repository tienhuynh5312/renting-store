
#ifndef _TRANSACTION_H
#define _TRANSACTION_H

#include <string>
#include "hashable.h"

class Transaction : public Hashable<int>
{
private:
  std::string transactionDetail;
protected:
public:
  Transaction() = delete; // Do not accept empty transaction.
  
  /**
   * @brief Construct a new Transaction
   * 
   * @param detail Detail of transaction.
   */
  Transaction(const std::string &detail);
  ~Transaction();

  /**
   * @brief Get the Transaction Detail
   * 
   * @return const std::string& Detail of transaction.
   */
  const std::string &getTransactionDetail() const;

  int getHash() const;
};

#endif
