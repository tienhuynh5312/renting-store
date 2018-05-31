#include <iostream>
#include "store.h"
#include <string>

std::string getInput()
{
  std::string input;
  //std::getline(std::cin,input);
  std::cin >> input;
  return input;
}

int main(int argc, char const *argv[])
{
  Store thisStore{"Tracking Inventory System", 1111};

  std::cout << "***********************************************" << std::endl;
  std::cout << thisStore.getStoreID() << ": " << thisStore.getStoreName() << std::endl;
  std::cout << "***********************************************" << std::endl;

  int choice = 0;
  while (choice != -1)
  {

    std::cout << "=======Command menu===========" << std::endl;
    std::cout << "-1. Exit " << std::endl;
    std::cout << "0. Read all the default files" << std::endl;
    std::cout << "1. Read customer files" << std::endl;
    std::cout << "2. Read Video files" << std::endl;
    std::cout << "3. Read Transaction files" << std::endl;
    std::cout << "Choose an option: ";
    std::cin >> choice;

    switch (choice)
    {
    case 0:
      thisStore.readFile(FileType::CUSTOMER, "data4customers.txt");
      thisStore.readFile(FileType::VIDEO, "data4movies.txt");
      thisStore.readFile(FileType::TRANSACTION, "data4commands.txt");
      break;
    case 1:

      thisStore.readFile(FileType::CUSTOMER, getInput());
      break;
    case 2:

      thisStore.readFile(FileType::VIDEO, getInput());
      break;
    case 3:

      thisStore.readFile(FileType::TRANSACTION, getInput());
      break;
    }
  }

  return 0;
}
