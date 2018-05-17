#include "borrowable.h"

Borrowable::Borrowable()
{
    itemBorrowed = 0;
    totalSupply = 10;
    borrowable = true;
    borrowingPrice = 0.0;
}

Borrowable::Borrowable(const int &total = 0, const double &price = 0.0, const bool &borrow = true)
    : borrowingPrice(price), borrowable(borrow)
{
    if (total < 0)
        totalSupply = 0;
    else
        totalSupply = total;
}

Borrowable::~Borrowable()
{
}

bool Borrowable::borrowItem(const int &quantity = 1)
{
    if (borrowable == false)
        return false;

    if (quantity > getCurrentStock())
        return false;
    else
    {
        itemBorrowed += quantity;
        return true;
    }
}
bool Borrowable::returnItem(const int &quantity = 1)
{
    if (quantity < 0)
        return false;
    else
    {
        itemBorrowed -= quantity;
    }
}

int Borrowable::getCurrentStock() const
{
    return totalSupply - itemBorrowed;
}

int Borrowable::getTotalStock() const
{
    return totalSupply;
}

bool Borrowable::isBorrowable() const
{
    return borrowable;
}

const double &Borrowable::getBorrowingPrice() const
{
    return borrowingPrice;
}

bool Borrowable::setTotalSupply(const int &total)
{
    totalSupply = total;
}
