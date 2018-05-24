//
//  drama.h
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#ifndef drama_h
#define drama_h

#include <stdio.h>
#include "video.h"

class Drama : public Video
{
public:
  Drama(){ videoType = VideoType::DRAMA; };
  virtual ~Drama();

  Drama(const std::string &title, int stock, const std::string &director);
  Drama(const std::string &title, int stock, const std::string &director, const Date& date);

  bool operator<(const Drama &rhs) const;
  bool operator==(const Drama &rhs) const;
};

#endif /* drama_h */
