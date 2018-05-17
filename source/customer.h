#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <string>

#include "person.h"

class Customer : public Person
{
private:
  // unique customer id
  int customerID;
protected:
  // count of all customers
  static int totalCustomers;

public:
  // customers need id
  Customer() = delete;
  // Customer(const int &id); // ask tien
  Customer(const std::string &first, const std::string &last, const int &id);
  ~Customer();
  const int &getCustomerID() const;
  const int &getTotalCustomers() const;
};

#endif
