//
//  comedy.cpp
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#include "comedy.h"

<<<<<<< HEAD
Comedy::~Comedy(){};

Comedy::Comedy(const std::string &title, int stock, const std::string &director) : Video(title, stock, director)
{
    videoType = VideoType::COMEDY;
};

Comedy::Comedy(const std::string &title, int stock, const std::string &director, std::string &major, int year) : Video(title, stock, director, Date(year))
{
    this->majorActor = major;
};

bool Comedy::operator<(const Comedy &rhs) const {
    
};
bool Comedy::operator>(const Comedy &rhs) const
{
    
    return *this > rhs;
};
bool Comedy::operator==(const Comedy &rhs) const {
    
};
bool Comedy::operator!=(const Comedy &rhs) const
{

    return !(*this == rhs);
};

bool Comedy::operator<=(const Comedy &rhs) const
{
    
    return (*this < rhs || *this == rhs);
};
bool Comedy::operator>=(const Comedy &rhs) const
{
    
    return (rhs <= *this);
};

std::ostream &operator>>(std::ostream &os, Comedy &obj){
};
=======
Comedy::~Comedy()
{
}

Comedy::Comedy(const std::string &title, int stock, const std::string &director) : Video(title, stock, director)
{
  videoType = VideoType::COMEDY;
}

Comedy::Comedy(const std::string &title, int stock, const std::string &director, const Date &date) : Video(title, stock, director, date)
{
  videoType = VideoType::COMEDY;
}

bool Comedy::operator<(const Comedy &rhs) const
{
  if (getTitle() < rhs.getTitle())
    return true;
  else if (getTitle() > rhs.getTitle())
    return false;
  else
  {
    if (getDate().getYear() < rhs.getDate().getYear())
      return true;
    else
      return false;
  }
}

bool Comedy::operator==(const Comedy &rhs) const
{
  if (getTitle() == rhs.getTitle() && getDate().getYear() == rhs.getDate().getYear())
    return true;
  else
    return false;
}
>>>>>>> design
