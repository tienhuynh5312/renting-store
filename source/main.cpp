#include <iostream>
#include "store.h"

int main(int argc, char const *argv[])
{
  Store thisStore{"Tien Huynh", 1111};
  thisStore.readFile(FileType::CUSTOMER, "../test/data4customers.txt");
  thisStore.readFile(FileType::VIDEO, "../test/data4movies.txt");
  thisStore.readFile(FileType::TRANSACTION, "../test/data4commands.txt");
  return 0;
}
