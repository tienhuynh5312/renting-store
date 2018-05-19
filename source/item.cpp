

#include <string>

#include "item.h"

// private

// protected
int Item::totalItems = 0;

Item::Item(const std::string &type) : Borrowable()
{
  ++totalItems;
  itemType = getItemType(type);
  itemID = 0;
}

Item::Item(const std::string &type, const int &id) : Item(type)
{
  itemID = id;
}

// public
Item::Item(const std::string &type, const int &id, const int &total, const double &price)
    : Item(type, id)
{
  fullPrice = price;
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
  if (itemType == ItemType::VIDEO)
    return "Video";
}

int Item::getTotalItems() const
{
  return totalItems;
}

ItemType Item::getItemType(const std::string &itemType)
{
  if (itemType == "Video")
    return ItemType::VIDEO;
}

int Item::getHash() const
{
  return Hashable<int>::getHash(itemID) + Hashable<int>::getHash(getItemType());
}