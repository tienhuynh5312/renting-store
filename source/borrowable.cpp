#include "borrowable.h"

Borrowable::Borrowable() : itemBorrowed(0), totalSupply(10),
                           borrowable(true), borrowingPrice(0.0)
{
}

Borrowable::Borrowable(const int &total, const double &price, const bool &borrow)
    : itemBorrowed(0), borrowingPrice(price), borrowable(borrow)
{

    if (total < 0)
        totalSupply = 0;
    else
        totalSupply = total;
}

Borrowable::~Borrowable()
{
}

bool Borrowable::borrowItem(const int &quantity)
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
bool Borrowable::returnItem(const int &quantity)
{
    if (quantity < 0)
        return false;
    else
    {
        itemBorrowed -= quantity;
        return true;
    }
}

int Borrowable::getCurrentStock() const
{
    return totalSupply - itemBorrowed;
}

const int &Borrowable::getTotalStock() const
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
    return true;
}
