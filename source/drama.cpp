//
//  drama.cpp
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#include "drama.h"
#include "video.h"

Drama::~Drama(){
    
};

Drama::Drama(const std::string &title, int stock, const std::string &director) : Video(title, stock, director) {
    
};
Drama::Drama(const std::string &title, int stock, const std::string &director, int year) : Video(title,stock, director, Date(year)) {
    
};

bool Drama::operator<(const Drama &) const{
    
};
bool Drama::operator>(const Drama &) const{
    
};
bool Drama::operator==(const Drama &) const{
    
};
bool Drama::operator!=(const Drama &) const{
    
};
bool Drama::operator<=(const Drama &) const{
    
};
bool Drama::operator>=(const Drama &) const{
    
};

std::ostream& operator>>(std::ostream& os, Drama& obj){
    
};


