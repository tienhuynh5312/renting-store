//
//  classics.cpp
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#include "classics.h"
#include "video.h"

<<<<<<< HEAD
Classics::~Classics(){

};
=======
Classics::~Classics() {}
>>>>>>> design

Classics::Classics(const std::string &title, int stock, const std::string &director) : Video(title, stock, director)
{
  videoType = VideoType::CLASSICS;
  majorActor = "";
}

Classics::Classics(const std::string &title, int stock, const std::string &director, const std::string &major, const Date &date) : Video(title, stock, director, date)
{
  majorActor = major;
  videoType = VideoType::CLASSICS;
}

bool Classics::operator<(const Classics &rhs) const
{
  if (getDate() < rhs.getDate())
    return true;
  else if (getDate() > rhs.getDate())
    return false;
  else
  {
    if (majorActor < rhs.majorActor)
      return true;
    else
      return false;
  }
}

bool Classics::operator==(const Classics &rhs) const
{
  if (getDate() == rhs.getDate() && majorActor == rhs.majorActor)
    return true;
  else
    return false;
}

const std::string &Classics::getMajorActor() const
{
  return majorActor;
}