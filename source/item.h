
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
private:
  double fullPrice;

protected:
  // unique item identification number
  int itemID;

  // type of item
  std::string itemType;

  // initialize in source
  static int totalItems;

public:
  // item needs id and type
  Item(void) = delete;
  Item(const int &id, const std::string &type);
  ~Item(void);
  double getFullPrice(void) const;
  int getItemID(void) const;
  const std::string& getItemType(void) const;
};

#endif
