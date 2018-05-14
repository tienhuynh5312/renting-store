
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
private:
  double fullPrice{0.0};

protected:
  // unique item identification number
  int itemID{0};
  
  // type of item
  std::string itemType{""};
  
  // initialize in source
  static int totalItems; 

public:

  std::string getItemType() const;
  std::string getItem() const;
  double getFullPrice() const;

};

#endif ITEM_H
