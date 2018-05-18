//
//  classics.cpp
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#include "classics.h"
#include "video.h"

Classics::~Classics(){};

Classics::Classics(const std::string &title, int stock, const std::string &director) : Video(title, stock, director)
{
  videoType = VideoType::CLASSICS;
};

Classics::Classics(const std::string &title, int stock, const std::string &director, std::string &major, int year) : Video(title, stock, director, Date(year))
{
  this->majorActor = major;
  videoType = VideoType::CLASSICS;
};

bool Classics::operator<(const Classics &rhs) const {

};
bool Classics::operator>(const Classics &rhs) const
{

  return *this > rhs;
};
bool Classics::operator==(const Classics &rhs) const {

};
bool Classics::operator!=(const Classics &rhs) const
{

  return !(*this == rhs);
};

bool Classics::operator<=(const Classics &rhs) const
{

  return (*this < rhs || *this == rhs);
};
bool Classics::operator>=(const Classics &rhs) const
{

  return (rhs <= *this);
};

std::ostream &operator>>(std::ostream &os, Classics &obj){

};
