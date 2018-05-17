//
//  classics.cpp
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#include "classics.h"
#include "video.h"

Classics::Classics() : Video(){
    
};
virtual Classics::~Classics(){
    
};

Classcis::Classics(const std::string &title, int stock, const std::string &director)
: Video(title,stock,director) {
    
};

Classiscs::Classics(const std::string &title, int stock, const std::string &director, std::string &majorActor,int year) : Video(title,stock,director,majorActor,year){
    
};


bool Classics::operator<(const Classics & rhs) const{
    
};
bool Classics::operator>(const Classics & rhs) const{
    
    return *this>rhs;
};
bool Classics::operator==(const Classics & rhs) const{
    
};
bool Classics::operator!=(const Classics & rhs) const{
    
    return !(*this == rhs);
};

bool Classics::operator<=(const Classics & rhs) const{
    
    return (*this < rhs || *this == rhs);
};
bool Classics::operator>=(const Classics & rhs) const{
    
    return (rhs <= *this);
};

friend Classics::std::istream& operator>>(std::istream& is, Classics& obj){
    
};


