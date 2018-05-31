
#ifndef video_h
#define video_h

#include <stdio.h>
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
  Video(); // Video need at least title
  virtual ~Video();

  Video(const std::string &title);
  Video(const std::string &title, const std::string &director);
  Video(const std::string &title, int stock, const std::string &director);
  Video(const std::string &title, int stock, const std::string &director, const Date &date);

  int getHash() const;
  virtual const std::string &getTitle() const;
  virtual const std::string &getDirector() const;
  virtual const Date &getDate() const;
  virtual std::string getVideoType() const;
  static VideoType getVideoType(const std::string &rhs);

  virtual void setTitle(const std::string &title);
  virtual void setDirector(const std::string &director);
  virtual void setDate(const Date &date);

  virtual bool operator<(const Video &) const;
  virtual bool operator==(const Video &) const;
};

#endif /* video_h */
