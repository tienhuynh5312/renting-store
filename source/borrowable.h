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
  Borrowable() = default;
  Borrowable(const int &total, const double &price = 0.0, const bool &borrow = true);

  ~Borrowable();

  bool borrowItem(const int &quantity);
  bool returnItem(const int &quantity);

  int getCurrentStock() const;
  int getTotalStock() const;
  bool isBorrowable() const;

  double getBorrowingPrice() const;

  bool setTotalSupply(const int &total);
}

#endif
