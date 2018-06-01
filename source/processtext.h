#pragma once
#ifndef _PROCESSTEXT_H
#define _PROCESSTEXT_H
#include <string>
#include "transaction.h"
#include "customer.h"
#include "video.h"
enum class FileType
{
  VIDEO,
  CUSTOMER,
  TRANSACTION
};

class ProcessText
{
public:
  ProcessText(){};
  virtual ~ProcessText(){};
  void readFile(const FileType& fileType, const std::string &path);

protected:
  virtual bool readTransaction(const std::string &command) = 0;
  virtual bool readCustomer(const std::string &command) = 0;
  virtual bool readVideo(const std::string &command) = 0;
};
#endif // !_PROCESSTEXT_H