

#ifndef classics_h
#define classics_h

#include <string>
#include "video.h"
#include <iostream>

using namespace std;

class Classics : public Video
{
public:
    friend ostream &operator<<(ostream &outStream, const Classics &rhs );
  Classics() { videoType = VideoType::CLASSICS; };
  virtual ~Classics();

  Classics(const std::string &title, int stock, const std::string &director);
  Classics(const std::string &title, int stock, const std::string &director, const std::string &majorActor, const Date &date);
  const std::string &getMajorActor() const;
  bool operator<(const Classics &rhs) const;
  bool operator==(const Classics &rhs) const;
  int getHash() const;


private:
  std::string majorActor;
};
#endif /* classics_h */
