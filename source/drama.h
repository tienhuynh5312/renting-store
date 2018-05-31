
#ifndef drama_h
#define drama_h

#include <stdio.h>
#include "video.h"
#include <iostream>

using namespace std;

class Drama : public Video
{
public:
  Drama() { videoType = VideoType::DRAMA; };
  virtual ~Drama();

  Drama(const std::string &title, int stock, const std::string &director);
  Drama(const std::string &title, int stock, const std::string &director, const Date &date);

  bool operator<(const Drama &rhs) const;
  bool operator==(const Drama &rhs) const;
  int getHash() const;
  friend ostream &operator<<(ostream &outStream, const Drama &rhs);
};

#endif /* drama_h */
