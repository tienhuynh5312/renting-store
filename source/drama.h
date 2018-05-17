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

class Drama : public Video{
public:
    Drama();
    virtual ~Drama();
    
    Drama(const std::string &title, int stock, const std::string &director);
    Drama(const std::string &title, int stock, const std::string &director, int year);
    
    
    virtual std::string getGenre() const override;
    virtual std::string toString() const override;
    virtual void displayMovieInfo() const override;
    
    bool operator<(const Drama &) const;
    bool operator>(const Drama &) const;
    bool operator==(const Drama &) const;
    bool operator!=(const Drama &) const;
    bool operator<=(const Drama &) const;
    bool operator>=(const Drama &) const;
    
    friend std::istream& operator>>(std::istream& is, Drama& obj);
    
private:
    const std::string Genre;
    const std::string movieType;
    
};

#endif /* drama_h */