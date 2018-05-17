
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
private:
  // price of item
  double fullPrice;
  // unique item identification number
  int itemID;
protected:
  // type of item
  std::string itemType;
  // count of all items
  static int totalItems;

public:
  // item needs id and type
  Item(void) = delete;
  Item(const int &id, const std::string &type);
  ~Item(void);
  double getFullPrice(void) const;
  int getItemID(void) const;
  const std::string &getItemType(void) const;
  const int &getTotalItems(void) const;
};

#endif
