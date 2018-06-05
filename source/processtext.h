/**
 * Project#4 : Inventory Tracking System
 * Tien Huynh, Erik Jose Maldonado, Byunggeun Park (BK)
 */

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
   * @brief Reads file from path
   * 
   * @param fileType type of file to be read
   * @param path path to file
   */
  void readFile(const FileType& fileType, const std::string &path);

protected:

  /**
   * @brief reads transactions 
   * 
   * @param command 
   * @return true if sucessfully read
   * @return false if not sucessfully read
   */
  virtual bool readTransaction(const std::string &command) = 0;

  /**
   * @brief reads customers
   * 
   * @param command 
   * @return true if sucessfully read
   * @return false if not sucessfully read
   */
  virtual bool readCustomer(const std::string &command) = 0;
  
  /**
   * @brief reads videos
   * 
   * @param command 
   * @return true if sucessfully read
   * @return false if not sucessfully read
   */
  virtual bool readVideo(const std::string &command) = 0;
};
#endif // !_PROCESSTEXT_H