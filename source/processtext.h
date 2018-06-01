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

  /**
   * @brief Construct a new Process Text object
   */
  ProcessText(){};

  /**
   * @brief Destroy the Process Text object
   */
  virtual ~ProcessText(){};

  /**
   * @brief 
   * 
   * @param fileType 
   * @param path 
   */
  void readFile(const FileType& fileType, const std::string &path);

protected:

  /**
   * @brief 
   * 
   * @param command 
   * @return true 
   * @return false 
   */
  virtual bool readTransaction(const std::string &command) = 0;

  /**
   * @brief 
   * 
   * @param command 
   * @return true 
   * @return false 
   */
  virtual bool readCustomer(const std::string &command) = 0;
  
  /**
   * @brief 
   * 
   * @param command 
   * @return true 
   * @return false 
   */
  virtual bool readVideo(const std::string &command) = 0;
};
#endif // !_PROCESSTEXT_H