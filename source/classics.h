//
//  classics.h
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#ifndef classics_h
#define classics_h

#include <stdio.h>
#include "video.h"
#include <ostream>

class Classics : public Video{
public:
    Classics() = delete;
    virtual ~Classics();
    
    Classics(const std::string &title, int stock, const std::string &director);
    Classics(const std::string &title, int stock, const std::string &director, std::string &majorActor,
             int year);

    
    bool operator<(const Classics & rhs) const;
    bool operator>(const Classics & rhs) const;
    bool operator==(const Classics & rhs) const;
    bool operator!=(const Classics & rhs) const;
    bool operator<=(const Classics & rhs) const;
    bool operator>=(const Classics & rhs) const;
    
    friend std::ostream& operator>>(std::ostream& os, Classics& obj);
    
private:
    std::string majorActor;
};
#endif /* classics_h */
