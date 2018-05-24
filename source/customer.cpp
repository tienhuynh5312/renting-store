
#include <string>

#include "person.h"
#include "customer.h"

Customer::Customer(const std::string &first, const std::string &last, const int &id) : Person(first, last), customerID(id)
{
  ++totalCustomers;
}

Customer::~Customer()
{
  --totalCustomers;
}

const int &Customer::getCustomerID() const
{
  return this->customerID;
}

const int &Customer::getTotalCustomers() const
{
  return totalCustomers;
}

int Customer::totalCustomers = 0;

bool Customer::operator==(const Customer& rhs) const
{
  return (customerID == rhs.customerID);
}

bool Customer::operator<(const Customer& rhs) const
{
  return (customerID < rhs.customerID);
}

bool Customer::operator<=(const Customer& rhs) const
{
  return (*this < rhs) || (*this == rhs);
}

std::ostream& operator<<(std::ostream& out, const Customer& rhs)
{
  return out << rhs.customerID;
}

int Customer::getHash() const
{
  return Hashable::getHash(customerID);
}