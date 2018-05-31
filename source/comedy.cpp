

#include "comedy.h"
#include <string>

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

int Comedy::getHash() const
{
  return Hashable::getHash(title) + Hashable::getHash(date.getYear());
}

bool Comedy::operator==(const Comedy &rhs) const
{
  if (getTitle() == rhs.getTitle() && getDate().getYear() == rhs.getDate().getYear())
    return true;
  else
    return false;
}

ostream &operator<<(ostream &outStream, const Comedy &rhs)
{

  outStream << rhs.getItemType() << "" << rhs.getTotalStock() << "" << rhs.getDirector() << ""
            << rhs.getTitle() << "" << rhs.getDate().getYear();
}
