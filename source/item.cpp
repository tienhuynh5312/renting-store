

#include <string>

#include "item.h"

// private

// protected
int Item::totalItems = 0;

Item::Item(const std::string &type) : Borrowable()
{
    itemID = totalItems++;
    itemType = type;
}

// public
Item::Item(const std::string &type, const int& total, const double& price)
    : itemID(totalItems), itemType(type), fullPrice(price)
{
  ++totalItems;
  setTotalSupply(total);
}

Item::~Item()
{
  --totalItems;
}

double Item::getFullPrice() const
{
  return fullPrice;
}

int Item::getItemID() const
{
  return itemID;
}

std::string Item::getItemType() const
{
  return itemType;
}

int Item::getTotalItems() const
{
  return totalItems;
}
