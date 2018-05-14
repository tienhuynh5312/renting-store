#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <string>

class Customer : public Person
{
private:
  int customerID;
  static int totalCustomers;

public:
  Customer();
  Customer(const int& id);
  ~Customer();
  int &getCustomerID() const;
  int &getTotalCustomers() const;
}
#endif
