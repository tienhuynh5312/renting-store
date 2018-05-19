//
//  drama.cpp
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#include "drama.h"
#include "video.h"

Drama::~Drama(){

};

Drama::Drama(const std::string &title, int stock, const std::string &director) : Video(title, stock, director)
{
  videoType = VideoType::DRAMA;
};
Drama::Drama(const std::string &title, int stock, const std::string &director, int year) : Video(title, stock, director, Date(year))
{
  videoType = VideoType::DRAMA;
}

bool Drama::operator<(const Drama &rhs) const
{
  if (getDirector() < rhs.getDirector())
    return true;
  else if (getDirector() > rhs.getTitle())
    return false;
  else
  {
    if (getTitle() < rhs.getTitle())
      return true;
    else if (getTitle() > rhs.getTitle())
      return false;
  }
}

bool Drama::operator>(const Drama &rhs) const {
    
    return *this > rhs;
};

bool Drama::operator==(const Drama &rhs) const {
    
    return (this->getDirector() == rhs.getDirector() &&
            this->getTitle() == rhs.getTitle());
};

bool Drama::operator!=(const Drama &rhs) const {
    return !(*this == rhs);
};

bool Drama::operator<=(const Drama &rhs) const {
    return ((*this < rhs) || *this == rhs);
};

bool Drama::operator>=(const Drama &rhs) const {
    return (rhs <= *this);
};

