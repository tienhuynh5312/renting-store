//
//  video.cpp
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#include "video.h"

Video::Video(const std::string &title) : Item("Video")
{
  date = Date();
  itemType = ItemType::VIDEO;
  this->title = title;
}

Video::Video(const std::string &title, const std::string &director) : Video(title)
{
  this->director = director;
}

Video::Video(const std::string &title, int stock, const std::string &director) : Video(title, director)
{
  setTotalSupply(stock);
}

Video::Video(const std::string &title, int stock, const std::string &director, const Date &date) : Video(title, stock, director)
{
  setDate(date);
}

Video::~Video()
{
}

const std::string &Video::getTitle() const
{
  return title;
}

const std::string &Video::getDirector() const
{
  return director;
}

const Date &Video::getDate() const
{
  return date;
}

void Video::setTitle(const std::string &title)
{
  this->title = title;
}

void Video::setDirector(const std::string &director)
{
  this->director = director;
}

void Video::setDate(const Date &date)
{
  this->date = date;
}

bool Video::operator<(const Video &rhs) const
{
  if (rhs.videoType != videoType)
    return false;
}

bool Video::operator==(const Video &rhs) const
{
  if (rhs.videoType != videoType)
    return false;
}

