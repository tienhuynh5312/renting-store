#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <string>

#include "person.h"
#include "hashable.h"
#include <ostream>

class Customer : public Person, public Hashable<int>
{
private:
  // unique customer id
  int customerID;
protected:
  // count of all customers
  static int totalCustomers;

public:
  // customers need id
  Customer():Person("N/A","N/A"), customerID(0) {};
  Customer(const int &id) = delete; // ask tien, we also need names to instantiate Person base class.
  Customer(const std::string &first, const std::string &last, const int &id);
  virtual ~Customer();
  const int &getCustomerID() const;
  const int &getTotalCustomers() const;
  int getHash() const;

  /*
  These following operations are needed for binary search tree to work properly.
  */
  bool operator==(const Customer& rhs) const;
  bool operator<(const Customer& rhs) const;
  bool operator<=(const Customer& rhs) const;

  friend std::ostream& operator<<(std::ostream& out, const Customer& rhs);

  // end

};

#endif
