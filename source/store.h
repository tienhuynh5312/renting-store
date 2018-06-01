#ifndef _STORE_H
#define _STORE_H

#include <string>
#include "database.h"
class Store
{
private:
  std::string storeName;
  int storeID;
  Database data;
public:
  Store();

  /**
   * @brief Construct a new Store object with name and store ID
   * 
   * @param name Name of store
   * @param id ID of store
   */
  explicit Store(const std::string &name, const int& id);
  ~Store();

  /**
   * @brief Get store name
   * 
   * @return const std::string& store name
   */
  const std::string &getStoreName() const;

  /**
   * @brief Get store ID
   * 
   * @return int& store ID.
   */
  const int &getStoreID() const;

  void readFile(const FileType& fType, const std::string& path);
  void executeCommand(const FileType& fType, const std::string& command);

};

#endif
