
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
   */
  Drama() { videoType = VideoType::DRAMA; };
  
  /**
   * @brief Destroy the Drama object
   */
  virtual ~Drama();

  /**
   * @brief Construct a new Drama object
   * 
   * @param title title of video
   * @param stock initial stock of video
   * @param director director of video
   */
  Drama(const std::string &title, int stock, const std::string &director);
  
  /**
   * @brief Construct a new Drama object
   * 
   * @param title title of video
   * @param stock initial stock of video
   * @param director director of video
   * @param date date of video
   */
  Drama(const std::string &title, int stock, const std::string &director, const Date &date);

  /**
   * @brief Arithematic operation
   * 
   * @param rhs object to compare this to
   * @return true if this is less than argument
   * @return false if this is greater than or equal to this object
   */
  bool operator<(const Drama &rhs) const;

  /**
   * @brief Arithematic operation
   * 
   * @param rhs object to compare this to
   * @return true if this is equal to argument object
   * @return false if this is not equal to this object
   */
  bool operator==(const Drama &rhs) const;
  
  /**
   * @brief Get the Hash object
   * 
   * @return int that represents hash for this object
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
