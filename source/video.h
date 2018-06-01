
#ifndef video_h
#define video_h

#include <ostream>
#include <string>
#include "date.h"
#include "item.h"
#include "hashable.h"

enum class VideoType
{
  CLASSICS,
  COMEDY,
  DRAMA
};

class Video : public Item
{
protected:
  std::string title;
  std::string director;
  Date date;
  VideoType videoType;

public:
  /**
   * @brief Construct a new Video object
   * 
   */
  Video(); // Video need at least title
  
  /**
   * @brief Destroy the Video object
   * 
   */
  virtual ~Video();

  /**
   * @brief Construct a new Video object
   * 
   * @param title 
   */
  Video(const std::string &title);

  /**
   * @brief Construct a new Video object
   * 
   * @param title 
   * @param director 
   */
  Video(const std::string &title, const std::string &director);
  
  /**
   * @brief Construct a new Video object
   * 
   * @param title 
   * @param stock 
   * @param director 
   */
  Video(const std::string &title, int stock, const std::string &director);
  
  /**
   * @brief Construct a new Video object
   * 
   * @param title 
   * @param stock 
   * @param director 
   * @param date 
   */
  Video(const std::string &title, int stock, const std::string &director, const Date &date);

  int getHash() const;
  
  /**
   * @brief Get the Title object
   * 
   * @return const std::string& 
   */
  virtual const std::string &getTitle() const;
  
  /**
   * @brief Get the Director object
   * 
   * @return const std::string& 
   */
  virtual const std::string &getDirector() const;

  /**
   * @brief Get the Date object
   * 
   * @return const Date& 
   */
  virtual const Date &getDate() const;
  
  /**
   * @brief Get the Video Type object
   * 
   * @return std::string 
   */
  virtual std::string getVideoType() const;

  /**
   * @brief Get the Video Type object
   * 
   * @param rhs 
   * @return VideoType 
   */
  static VideoType getVideoType(const std::string &rhs);

  /**
   * @brief Set the Title object
   * 
   * @param title 
   */
  virtual void setTitle(const std::string &title);

  /**
   * @brief Set the Director object
   * 
   * @param director 
   */
  virtual void setDirector(const std::string &director);

  /**
   * @brief Set the Date object
   * 
   * @param date 
   */
  virtual void setDate(const Date &date);

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool operator<(const Video &) const;

  /**
   * @brief 
   * 
   * @return true 
   * @return false 
   */
  virtual bool operator==(const Video &) const;

  /**
   * @brief 
   * 
   * @param out 
   * @param rhs 
   * @return std::ostream& 
   */
  friend std::ostream& operator<<(std::ostream& out, const Video& rhs);
};

#endif /* video_h */
