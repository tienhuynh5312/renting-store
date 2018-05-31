
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

std::string Video::getVideoType() const
{
  if (videoType == VideoType::CLASSICS)
    return "Classics";
  else if (videoType == VideoType::COMEDY)
    return "Comedy";
  else if (videoType == VideoType::DRAMA)
    return "Drama";
}
VideoType Video::getVideoType(const std::string &rhs)
{
  if (rhs == "Comedy")
    return VideoType::COMEDY;
  else if (rhs == "Classics")
    return VideoType::CLASSICS;
  else if (rhs == "Drama")
    return VideoType::DRAMA;
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

int Video::getHash() const
{
  return Hashable::getHash(title) + Hashable::getHash(title) + Hashable::getHash(director) + Hashable::getHash(date.getYear());
}
