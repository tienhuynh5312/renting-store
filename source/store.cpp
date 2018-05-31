#include "store.h"

Store::Store()
{
  storeID = 0;
  storeName = "Inventory Tracking System";
}
Store::Store(const std::string &name, const int &id) : storeName(name), storeID(id) {}

Store::~Store() {}

void Store::readFile(const FileType &fType, const std::string &path)
{
  data.readFile(fType, path);
}

void Store::executeCommand(const FileType &fType, const std::string &command)
{
  switch (fType)
  {
  case FileType::TRANSACTION:
    data.readTransaction(command);
    break;
  case FileType::CUSTOMER:
    data.readCustomer(command);
    break;
  case FileType::VIDEO:
    data.readVideo(command);
    break;
  }
}
