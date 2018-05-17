#ifndef _BORROWABLE_H
#define _BORROWABLE_H

class Borrowable
{
private:
  int itemBorrowed; // number of items is borrowed
  int totalSupply; // total inital stock supply that this item has.
  bool borrowable;
  double borrowingPrice;

public:

  /*
  All the implmentation will be borrowable.cpp
  */
  Borrowable();
  Borrowable(const int &total = 0, const double &price = 0.0, const bool& borrow = true);
  virtual ~Borrowable();

  /**
   * @brief Borrow item from inventory
   * 
   * @param quantity number of item will be borrowed.
   * @return true if borrowing succeed.
   * @return false if borrowing failed.
   */
  virtual bool borrowItem(const int &quantity = 1) = 0;

  /**
   * @brief Check item borrowable
   * 
   * @return true if item can be borrowed.
   * @return false if item cannot be borrowed.
   */
  virtual bool isBorrowable() const = 0;

  /**
   * @brief return item back to inventory.
   * 
   * @param quantity number of item returned
   * @return true if returning succeed.
   * @return false if returning failed.
   */
  virtual bool returnItem(const int &quantity = 1) = 0;

  /**
   * @brief Get the Borrowing Price object
   * 
   * @return const double& 
   */
  virtual const double &getBorrowingPrice() const = 0;
  
  /**
   * @brief How many item left in inventory.
   * 
   * @return const int& number of item that we have left in inventory
   */
  virtual const int &getCurrentStock() const = 0;

  /**
   * @brief Initial total stock that we have at the beginning.
   * 
   * @return const int& Return total stock.
   */
  virtual const int &getTotalStock() const = 0;

  /**
   * @brief Set the Total Supply for this item
   * 
   * @param total total stock the store have in total.
   * @return true if everything goes right.
   * @return false if things goes wrong.
   */
  virtual bool setTotalSupply(const int &total);
};

#endif
