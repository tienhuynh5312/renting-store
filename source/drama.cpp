
#include "drama.h"
#include "video.h"

Drama::~Drama(){
    
};

Drama::Drama(const std::string &title, int stock, const std::string &director) : Video(title, stock, director)
{
  videoType = VideoType::DRAMA;
};
Drama::Drama(const std::string &title, int stock, const std::string &director, const Date& date) : Video(title, stock, director, date)
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


bool Drama::operator==(const Drama &rhs) const {
    
    return (this->getDirector() == rhs.getDirector() &&
            this->getTitle() == rhs.getTitle());
}

ostream &operator<<(ostream &outStream, const Drama &rhs) {

  if ( rhs.getTitle() == "D")
  {
    outStream << rhs.getItemType() << "" <<rhs.getTotalStock() << "" << rhs.getDirector() << ""
              << rhs.getTitle() << "" << rhs.getDate().getYear();
  }
}


