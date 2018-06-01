

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
   * @brief
   * 
   * @param 
   * 
   * @return String reference to major actor
   */
  const std::string &getMajorActor() const;

  /**
   * @brief
   * 
   * @param
   * 
   * @return
   */
  bool operator<(const Classics &rhs) const;

  /**
   * @brief
   * 
   * @param
   * 
   * @return
   */
  bool operator==(const Classics &rhs) const;

  /**
   * @brief
   * 
   * @param
   * 
   * @return
   */
  int getHash() const;

private:
  std::string majorActor;
};
#endif /* classics_h */
