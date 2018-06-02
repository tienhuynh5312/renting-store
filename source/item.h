/**
 * Project#4 : Inventory Tracking System
 * Tien Huynh, Erik Jose Maldonado, Byunggeun Park (BK)
 */

#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "borrowable.h"
#include "hashable.h"
#include <ostream>

enum class ItemType
{
  VIDEO
};

class Item : public Borrowable, public Hashable
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
  Item(){}; // Dont allow create new Item without specifying item type

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
  static ItemType getItemType(const std::string& itemType);
  int getHash() const;

    /*
  These following operations are needed for binary search tree to work properly.
  */
  bool operator==(const Item& rhs) const;
  bool operator<(const Item& rhs) const;
  bool operator<=(const Item& rhs) const;

  friend std::ostream& operator<<(std::ostream& out, const Item& rhs);

  // end
};

#endif
