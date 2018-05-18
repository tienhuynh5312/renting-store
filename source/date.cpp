//
//  date.cpp
//  Movie
//
//  Created by Byunggeun Park on 5/15/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#include <stdio.h>
#include "date.h"

Date::Date() : year(0), month(0), day(0)
{
}

Date::Date(const Date& date)
{
    *this = date;
}

Date::~Date()
{
}

Date::Date(const int &y, const int &m, const int &d)
    : year(y), month(m), day(d)
{
}

int Date::getYear() const
{
    return year;
};

int Date::getMonth() const
{
    return month;
};

int Date::getDay() const
{
    return day;
};

void Date::setYear(int year)
{
    this->year = year;
}

void Date::setMonth(int month)
{
    this->month = month;
}

void Date::setDay(int day)
{
    this->day = day;
}

bool Date::operator<(const Date &rhs) const
{

    return (*this < rhs);
};

bool Date::operator>(const Date &rhs) const
{

    return (*this > rhs);
};

bool Date::operator==(const Date &rhs) const
{

    if (this->year == rhs.year && this->month == rhs.month && this->day == rhs.day)
        return true;

    return false;
};

bool Date::operator!=(const Date &rhs) const
{

    return !(*this == rhs);
};

bool Date::operator<=(const Date &rhs) const
{

    return ((*this < rhs) || (*this == rhs));
};

bool Date::operator>=(const Date &rhs) const
{

    return ((*this > rhs) || (*this == rhs));
};

Date& Date::operator=(const Date& date)
{
    setDay(date.getDay());
    setMonth(date.getMonth());
    setYear(date.getYear());
    return *this;
}