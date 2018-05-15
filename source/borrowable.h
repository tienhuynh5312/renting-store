#ifndef _BORROWABLE_H
#define _BORROWABLE_H

class Borrowable
{
private:
  int itemNumber;
  int totalSupply;
  bool borrowable;
  double borrowingPrice;

public:
  Borrowable();
  Borrowable(const int &total = 0, const double &price = 0.0);

  ~Borrowable();

  bool borrowItem(const int &quantity);
  bool returnItem(const int &quantity);

  int &getCurrentStock() const;
  int &getTotalStock() const;
  bool isBorrowable() const;

  double &getBorrowingPrice() const;
}

#endif
