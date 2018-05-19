//
//  comedy.cpp
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#include "comedy.h"
#include "video.h"

Comedy::~Comedy(){};

Comedy::Comedy(const std::string &title, int stock, const std::string &director) : Video(title, stock, director)
{
    videoType = VideoType::COMEDY;
};

Comedy::Comedy(const std::string &title, int stock, const std::string &director, std::string &major, int year) : Video(title, stock, director, Date(year))
{
    this->majorActor = major;
};

bool Comedy::operator<(const Comedy &rhs) const {
    
};
bool Comedy::operator>(const Comedy &rhs) const
{
    
    return *this > rhs;
};
bool Comedy::operator==(const Comedy &rhs) const {
    
};
bool Comedy::operator!=(const Comedy &rhs) const
{

    return !(*this == rhs);
};

bool Comedy::operator<=(const Comedy &rhs) const
{
    
    return (*this < rhs || *this == rhs);
};
bool Comedy::operator>=(const Comedy &rhs) const
{
    
    return (rhs <= *this);
};

std::ostream &operator>>(std::ostream &os, Comedy &obj){
};
