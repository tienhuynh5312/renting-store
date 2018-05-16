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

class Classics : public Video{
private:
    Classics();
    virtual ~Classics();
    
    Classics(const std::string &title, int stock, const std::string &director);
    Classics(const std::string &title, int stock, const std::string &director, std::string &majorActor,
             int year);
    
    virtual std::string getGenre() const override;
    
    virtual std::string toString() const override;
    virtual void displayMovieInfo() const override;
    

    bool operator<(const Classics & rhs) const;
    bool operator>(const Classics & rhs) const;
    bool operator==(const Classics & rhs) const;
    bool operator!=(const Classics & rhs) const;
    bool operator<=(const Classics & rhs) const;
    bool operator>=(const Classics & rhs) const;
    
    friend std::istream& operator>>(std::istream& is, Classics& obj);
    
public:
    const std::string Genre;
    const std::string movieType;
    const std::string majorActor;
};
#endif /* classics_h */
