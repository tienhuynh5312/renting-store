//
//  date.h
//  Movie
//
//  Created by Byunggeun Park on 5/15/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#ifndef date_h
#define date_h


class Date
{
private:
    int year;
    int month;
    int day;

public:
   Date();
    ~Date();
    Date(int year);
    Date(int year, int month);
    Date(int year, int month, int day);
    
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    
    void setYear(int year) { this->year = year;};
    void setMonth(int month){ this->month = month;};
    void setDay(int day){ this->day = day;};
    
    bool operator<(const Date& rhs) const;
    bool operator>(const Date& rhs) const;
    bool operator==(const Date& rhs) const;
    bool operator!=(const Date& rhs) const;
    bool operator<=(const Date& rhs) const;
    bool operator>=(const Date& rhs) const;

};


#endif /* date_h */
