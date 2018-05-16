//
//  date.cpp
//  Movie
//
//  Created by Byunggeun Park on 5/15/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#include <stdio.h>
#include "date.h"

Date::Date() : year(0), month(0), day(0){
    
}

Date::~Date(){
    
}

Date::Date(int year) : year(year), month(0), day(0) {
    
};

Date::Date(int year, int month) : year(year), month(month), day(0) {
    
};

Date::Date(int year, int month, int day) : year(year), month(month), day(0){
    
};

int Date::getYear() const{
    return year;
};

int Date::getMonth() const{
    return month;
};

int Date::getDay() const{
    return day;
};

//void setYear(int year);
//void setMonth(int month);
//void setDay(int day);

bool Date::operator<(const Date& rhs) const{
    
    return (*this < rhs);
};

bool Date::operator>(const Date& rhs) const{
    
    return (*this > rhs);
};

bool Date::operator==(const Date& rhs) const{
    
    if ( this->year == rhs.year
        && this->month == rhs.month
        && this->day == rhs.day)
        return true;
    
    return false;
};

bool Date::operator!=(const Date& rhs) const{
    
    return !(*this==rhs);
};

bool Date::operator<=(const Date& rhs) const{
    
    return ((*this < rhs) || (*this == rhs));
};

bool Date::operator>=(const Date& rhs) const{
    
    return ((*this > rhs) || (*this == rhs));
};
