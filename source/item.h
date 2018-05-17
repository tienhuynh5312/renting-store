#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "borrowable.h"

enum class ItemType
{
  MOVIE
};

class Item : public Borrowable
{
private:
  // price of item
  double fullPrice;

protected:
  // unique item identification number
  int itemID;
  // type of item
  std::string itemType;

  // initialize in source
  static int totalItems;

public:
  Item() = delete; // Dont allow create new Item without specifying item type
  explicit Item(const std::string &type);
  Item(const std::string &type, const int& total, const double& price = 0.0);

  ~Item();
  std::string getItemType() const;
  double getFullPrice() const;
  int getItemID() const;
  int getTotalItems() const;
  static Item *Create(ItemType type);
};

#endif
