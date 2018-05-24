//
//  video.h
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#ifndef video_h
#define video_h

#include <stdio.h>
#include <string>
#include "date.h"
#include "item.h"
enum class VideoType
{
  CLASSICS,
  COMEDY,
  DRAMA
};
class Classics;

class Video : public Item
{
private:
  std::string title;
  std::string director;
  Date date;

protected:
  VideoType videoType;

public:
  Video(); // Video need at least title
  virtual ~Video();

  Video(const std::string &title);
  Video(const std::string &title, const std::string &director);
  Video(const std::string &title, int stock, const std::string &director);
  Video(const std::string &title, int stock, const std::string &director, const Date &date);

  virtual const std::string &getTitle() const;
  virtual const std::string &getDirector() const;
  virtual const Date &getDate() const;
  virtual std::string getVideoType() const;
  static VideoType getVideoType(const std::string& rhs);

  virtual void setTitle(const std::string &title);
  virtual void setDirector(const std::string &director);
  virtual void setDate(const Date &date);

  virtual bool operator<(const Video &) const;
  virtual bool operator==(const Video &) const;
};

#endif /* video_h */
