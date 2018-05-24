#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <string>

#include "person.h"
#include "hashable.h"
#include <ostream>
#include <list>
#include "transaction.h"

class Customer : public Person, Hashable
{
private:
  // unique customer id
  int customerID;
  std::list<Transaction *> myTransaction;

protected:
  // count of all customers
  static int totalCustomers;

public:
  // customers need id
  Customer() : Person("N/A", "N/A") { customerID = 0; };
  Customer(const int &id) : Person("N/A", "N/A") { customerID = id; };
  Customer(const std::string &first, const std::string &last, const int &id);
  virtual ~Customer();
  const int &getCustomerID() const;
  const int &getTotalCustomers() const;
  int getHash() const;
  /*
  These following operations are needed for binary search tree to work properly.
  */
  bool operator==(const Customer &rhs) const;
  bool operator<(const Customer &rhs) const;
  bool operator<=(const Customer &rhs) const;

  friend std::ostream &operator<<(std::ostream &out, const Customer &rhs);

  // end
};

#endif
