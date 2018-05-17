
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
private:
protected:
  // price of item
  double fullPrice;
  // unique item identification number
  int itemID;
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
  std::string getItemType(void) const;
  int getTotalItems(void) const;
};

#endif
