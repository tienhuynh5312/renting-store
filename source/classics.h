

#ifndef classics_h
#define classics_h

#include <string>
#include "video.h"
#include <iostream>

using namespace std;

class Classics : public Video
{
public:
  
  /**
   * @brief Operator overload that returns an ostream object reference.
   * 
   * @param outStream ostream reference to be returned
   * @param rhs Classics object to send to ostream
   * 
   * @return ostream containing Classics object data
   */
  friend ostream &operator<<(ostream &outStream, const Classics &rhs);
  
  
  /**
   * @brief Construct a classics object with the videoType set to classic.
   */
  Classics() { videoType = VideoType::CLASSICS; };
  
  /**
   * @brief Destructor for classics object.
   */
  virtual ~Classics();

  /**
   * @brief Construct a classics object with the given parameters.
   * 
   * @param title Title of classics video
   * @param stock Initial stock of classics video
   * @param director Director of classics video
   */
  Classics(const std::string &title, int stock, const std::string &director);

  /**
   * @brief
   * 
   * @param title Title if classics video
   * @param stock Initial stock of classics video
   * @param director Director of classics video
   * @param majorActor Major actor for classics video
   * @param date Date of classics video
   */
  Classics(const std::string &title, int stock, const std::string &director, const std::string &majorActor, const Date &date);

  /**
   * @brief Returns string refrence to major actor for this classics movie.
   * 
   * @return String reference to major actor
   */
  const std::string &getMajorActor() const;

  /**
   * @brief Operator overload for classics object. Compares this object to parameter object.
   * 
   * @param rhs Classics object to compare this object to
   * 
   * @return true if this is less than argument
   */
  bool operator<(const Classics &rhs) const;

  /**
   * @brief Operator overload for classics object. Compares this object to parameter object.
   * 
   * @param rhs Classics object to compare this object to
   * 
   * @return true if this object is euql to argument
   */
  bool operator==(const Classics &rhs) const;

  /**
   * @brief Returns hash for this object.
   * 
   * @return int that represent hash of this object.
   */
  int getHash() const;

private:
  std::string majorActor;
};
#endif /* classics_h */
