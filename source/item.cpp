

#include <string>

#include "item.h"

// private

// protected
int Item::totalItems = 0;

Item::Item(const std::string &type) : Borrowable()
{
  ++totalItems;
  itemType = getItemType(type);
  itemID = totalItems;
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
  else
    return "";
}

int Item::getTotalItems() const
{
  return totalItems;
}

ItemType Item::getItemType(const std::string &itemType)
{
  if (itemType == "Video")
    return ItemType::VIDEO;
  else
    return ItemType::INVALID;
}

/*
  These following operations are needed for binary search tree to work properly.
  */
bool Item::operator==(const Item &rhs) const
{
  return (itemID == rhs.itemID) && (itemType == rhs.itemType);
}

bool Item::operator<(const Item &rhs) const
{
  if (itemID < rhs.itemID)
    return true;
  else if (itemID > rhs.itemID)
    return false;
  else
  {
    if (itemType < rhs.itemType)
      return true;
    else
      return false;
  }
}

bool Item::operator<=(const Item &rhs) const
{
  return (*this < rhs) || (*this == rhs);
}

std::ostream &operator<<(std::ostream &out, const Item &rhs)
{
  return out << "[ID:" << rhs.itemID << "]";
}

int Item::getHash() const
{
  return Hashable::getHash(this->itemID);
}
// end