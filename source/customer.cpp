
#include <string>

#include "person.h"
#include "customer.h"

int Customer::totalCustomers = 0;

Customer::Customer(const std::string &first, const std::string &last, const int &id) : Person(first, last), customerID(id)
{
  totalCustomers++;
}

Customer::~Customer()
{
  totalCustomers--;
}

const int &Customer::getCustomerID() const
{
  return this->customerID;
}

const int &Customer::getTotalCustomers()
{
  return totalCustomers;
}

bool Customer::linkTransaction(std::shared_ptr<Transaction> trans)
{
  myTransaction.push_front(trans);
  return true;
}
bool Customer::operator==(const Customer &rhs) const
{
  return (customerID == rhs.customerID);
}

bool Customer::operator<(const Customer &rhs) const
{
  return (customerID < rhs.customerID);
}

bool Customer::operator<=(const Customer &rhs) const
{
  return (*this < rhs) || (*this == rhs);
}

std::ostream &operator<<(std::ostream &out, const Customer &rhs)
{
  out << std::endl << "[ID: " << rhs.customerID << "] " << rhs.firstName << " " << rhs.lastName << std::endl;
  
  out << "==Transaction History (Recently)==" << std::endl;
  for (const auto& it : rhs.myTransaction)
  {
    if (auto trans = it.lock())
      out << trans->getTransactionDetail() << std::endl;
  }
  out << "==================================" << std::endl;
  return out;
}

int Customer::getHash() const
{
  return Hashable::getHash(customerID);
}
