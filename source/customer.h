#ifndef _CUSTOMER_H
#define _CUSTOMER_H

#include <string>

#include "person.h"
#include "hashable.h"
#include <ostream>
#include <list>
#include "transaction.h"
#include <memory>

class Customer : public Person, public Hashable
{
private:
  // unique customer id
  int customerID;
  // weak transaction list
  std::list<std::weak_ptr<Transaction>> myTransaction;

protected:
  // count of all customers
  static int totalCustomers;

public:
  /**
   * @brief Construct a new Customer object
   */
  Customer() : Person("N/A", "N/A") { customerID = 0; };

  /**
   * @brief Construct a new Customer object
   * 
   * @param id id for customer
   */
  Customer(const int &id) : Person("N/A", "N/A") { customerID = id; };

  /**
   * @brief Construct a new Customer object
   * 
   * @param first first name
   * @param last last name
   * @param id customer id
   */
  Customer(const std::string &first, const std::string &last, const int &id);

  /**
   * @brief Destroy the Customer object
   */
  virtual ~Customer();

  /**
   * @brief Get the Customer I D object
   * 
   * @return const int& 
   */
  const int &getCustomerID() const;

  /**
   * @brief Get the Total Customers object
   * 
   * @return const int& 
   */
  static const int &getTotalCustomers();

  /**
   * @brief 
   * 
   * @param trans transaction
   * @return true if the transaction sucessfully linked
   * @return false if the transaction did not sucessfully link
   */
  bool linkTransaction(std::shared_ptr<Transaction> trans);

  /**
   * @brief Get the Hash object
   * 
   * @return int 
   */
  int getHash() const;
  
  /*
  These following operations are needed for binary search tree to work properly.
  */
  bool operator==(const Customer &rhs) const;

  /**
   * @brief Comparison operation
   * 
   * @param rhs object to compare to
   * @return true if this customer is less than argument
   * @return false if this customer is greater than or equal to
   */
  bool operator<(const Customer &rhs) const;

  /**
   * @brief Comparision operation
   * 
   * @param rhs 
   * @return true if this customer is greater than or equal to
   * @return false if this customer is less than argument
   */
  bool operator<=(const Customer &rhs) const;

  /**
   * @brief Overload operator 
   * 
   * @param out outstream object
   * @param rhs customer object to com
   * @return std::ostream& 
   */
  friend std::ostream &operator<<(std::ostream &out, const Customer &rhs);

  // end
};

#endif
