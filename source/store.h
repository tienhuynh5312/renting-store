#ifndef _STORE_H
#define _STORE_H
#include <string>
class Store
{
  private:
  std::string storeName;
  int storeID;

  public:
  Store();
  explicit Store(const std::string& name);
  ~Store();

  std::string& getStoreName() const;
  int& getStoreID() const;
}

#endif
