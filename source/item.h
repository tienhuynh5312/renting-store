#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "borrowable.h"
#include "hashable.h"

enum class ItemType
{
  VIDEO
};

class Item : public Borrowable, public Hashable<int>
{
private:
  // price of item
  double fullPrice;

protected:
  // unique item identification number
  int itemID;
  // type of item
  ItemType itemType;

  // initialize in source
  static int totalItems;

public:
  Item() = delete; // Dont allow create new Item without specifying item type

  /**
   * @brief Construct a new Item object
   * 
   * @param type Type/
   */
  explicit Item(const std::string& type);

  /**
   * @brief Construct a new Item object
   * 
   * @param type 
   * @param id 
   */
  Item(const std::string &type, const int& id);

  /**
   * @brief Construct a new Item with item type, total stock, and price
   * 
   * @param type Item type
   * @param total Total stock.
   * @param price Price.
   */
  Item(const std::string &type, const int& id, const int& total, const double& price = 0.0);

  virtual ~Item();

  /**
   * @brief Get the Item Type
   * 
   * @return std::string Item type.
   */
  std::string getItemType() const;

  /**
   * @brief Get the Full Price
   * 
   * @return double Full price.
   */
  double getFullPrice() const;

  /**
   * @brief Get the Item ID
   * 
   * @return int Item ID.
   */
  int getItemID() const;

  /**
   * @brief Get the Total Items
   * 
   * @return int 
   */
  int getTotalItems() const;
  static Item *Create(ItemType type);
  static ItemType getItemType(const std::string& itemType);
};

#endif
