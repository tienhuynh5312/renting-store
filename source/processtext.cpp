#include "processtext.h"
#include <fstream>
#include <iostream>

void ProcessText::readFile(const FileType &fileType, const std::string &path)
{
  /*
  It is a common practice to wrap reading file
  inside try-catch block to prevent crashes due to unknown errors
  due to IO procedures.
  */
  std::ifstream inFile;
  try
  {
    inFile.open(path);
    if (!inFile)
      std::cout << "Cannot read: " << path << std::endl;
    else
    {
      std::string newLine{};
      while (std::getline(inFile, newLine))
      {
        if (fileType == FileType::VIDEO)
        {
          readVideo(newLine);
        }
        else if (fileType == FileType::CUSTOMER)
        {
          readCustomer(newLine);
        }
        else if (fileType == FileType::TRANSACTION)
        {
          readTransaction(newLine);
        }
      }
    }
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
}