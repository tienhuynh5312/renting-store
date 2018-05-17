#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <string>

#include "person.h"

class Customer : public Person
{
private:
protected:
  // unique customer id
  int customerID;
  // count of all customers
  static int totalCustomers;

public:
  // customers need id
  Customer() = delete;
  // ID will be handle automatically on this class
  // this helps us not having duplicated ID.
  // Customer(const int &id); // ask tien
  Customer(const std::string &first, const std::string &last, const int &id);
  virtual ~Customer();
  const int &getCustomerID() const;
  const int &getTotalCustomers() const;
};

#endif
