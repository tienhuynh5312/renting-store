//
//  classics.h
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#ifndef classics_h
#define classics_h

#include <string>
#include "video.h"

class Classics : public Video
{
public:
  Classics() = delete;
  virtual ~Classics();

  Classics(const std::string &title, int stock, const std::string &director);
  Classics(const std::string &title, int stock, const std::string &director, const std::string &majorActor, const Date &date);
  const std::string &getMajorActor() const;
  bool operator<(const Classics &rhs) const;
  bool operator==(const Classics &rhs) const;

private:
  std::string majorActor;
};
#endif /* classics_h */
