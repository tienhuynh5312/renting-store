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

  virtual std::string getGenre() const = 0;
  virtual std::string toString() const = 0;
  virtual void displayMovieInfo() const = 0;

  std::string getTitle() const;
  std::string getDirector() const;
  const Date &getDate() const;

  void setTitle(const std::string &title);
  void setDirector(const std::string &director);
  void setDate(const Date &date);

  virtual bool operator<(const Video &) const = 0;
  virtual bool operator==(const Video &) const = 0;
};

#endif /* video_h */
