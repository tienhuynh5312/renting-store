

#include <string>

#include "item.h"

// private

// protected
int Item::totalItems = 0;

// public
Item::Item(const int &id, const std::string &type)
    : itemID(id), itemType(type), fullPrice(0.0)
{
}

Item::~Item()
{
}

double Item::getFullPrice() const
{
  return this->fullPrice;
}

int Item::getItemID() const
{
  return this->itemID;
}

std::string Item::getItemType() const
{
  return this->itemType;
}
