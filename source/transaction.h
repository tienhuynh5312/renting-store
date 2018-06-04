/**
 * Project#4 : Inventory Tracking System
 * Tien Huynh, Erik Jose Maldonado, Byunggeun Park (BK)
 */

#ifndef _TRANSACTION_H
#define _TRANSACTION_H

#include <string>
#include "hashable.h"
#include <ostream>

class Transaction : public Hashable
{
private:
  std::string transactionDetail;

protected:
public:
  Transaction() { transactionDetail = ""; };

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
  /*
  These following operations are needed for binary search tree to work properly.
  */
  bool operator==(const Transaction &rhs) const;
  bool operator<(const Transaction &rhs) const;
  bool operator<=(const Transaction &rhs) const;

  friend std::ostream &operator<<(std::ostream &out, const Transaction &rhs);

  // end
};

#endif
