#ifndef _BORROWABLE_H
#define _BORROWABLE_H

class Borrowable
{
private:
  int itemBorrowed;
  int totalSupply;
  bool borrowable;
  double borrowingPrice;

public:
  // borrowable item needs details
  Borrowable() 
  {

  }

  Borrowable(const int &total = 0, const double &price = 0.0, const bool& borrow = true)
  {
    // init
  }

  virtual ~Borrowable()
  {
    
  }

  virtual bool borrowItem(const int &quantity) = 0;
  virtual bool isBorrowable() const = 0;
  virtual bool returnItem(const int &quantity) = 0;
  virtual const double &getBorrowingPrice() const = 0;
  virtual const int &getCurrentStock() const = 0; // are these the same?
  virtual const int &getTotalStock() const = 0; // ask tien
};

#endif
