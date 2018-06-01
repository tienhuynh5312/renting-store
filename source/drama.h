
#ifndef drama_h
#define drama_h

#include <stdio.h>
#include "video.h"
#include <iostream>

using namespace std;

class Drama : public Video
{
public:
  /**
   * @brief Construct a new Drama object
   * 
   */
  Drama() { videoType = VideoType::DRAMA; };
  /**
   * @brief Destroy the Drama object
   * 
   */
  virtual ~Drama();

  /**
   * @brief Construct a new Drama object
   * 
   * @param title 
   * @param stock 
   * @param director 
   */
  Drama(const std::string &title, int stock, const std::string &director);
  /**
   * @brief Construct a new Drama object
   * 
   * @param title 
   * @param stock 
   * @param director 
   * @param date 
   */
  Drama(const std::string &title, int stock, const std::string &director, const Date &date);

  /**
   * @brief Arithematic operation
   * 
   * @param rhs 
   * @return true 
   * @return false 
   */
  bool operator<(const Drama &rhs) const;
  bool operator==(const Drama &rhs) const;
  /**
   * @brief Get the Hash object
   * 
   * @return int 
   */
  int getHash() const;
  /**
   * @brief output stream
   * 
   * @param outStream 
   * @param rhs 
   * @return ostream& 
   */
  friend ostream &operator<<(ostream &outStream, const Drama &rhs);
};

#endif /* drama_h */
