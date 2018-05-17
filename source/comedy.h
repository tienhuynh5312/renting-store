//
//  comedy.h
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#ifndef comedy_h
#define comedy_h

#include <stdio.h>
#include "video.h"

class Comedy : public Video{
public:
    Comedy();
    virtual ~Comedy();
    
    Comedy(const std::string &title, int stock, const std::string &director);
    Comedy(const std::string &title, int stock, const std::string &director, int year);
    

    
    
    bool operator<(const Comedy & rhs) const;
    bool operator>(const Comedy & rhs) const;
    bool operator==(const Comedy & rhs) const;
    bool operator!=(const Comedy & rhs) const;
    bool operator<=(const Comedy & rhs) const;
    bool operator>=(const Comedy & rhs) const;
    
    friend std::istream& operator>>(std::istream& is, Comedy& obj);
    
private:
    const std::string movieType;
};

#endif /* comedy_h */
