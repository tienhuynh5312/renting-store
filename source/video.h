//
//  video.h
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#ifndef video_h
#define video_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <queue>
#include "date.h"

class Video {
private:
    
    std::string title {""};
    std::string director {""};
    Date date{0,0,0};
    int stock {0};
    

public:
    Video();
    ~Video();
    
    Video(const std::string &title);
    Video(const std::string &title, const std::string &directr);
    Video(const std::string &title, int stock, const std::string &director);
    Video(const std::string &title, int stock, const std::string &director, int year);
    Video(const std::string &title, int stock, const std::string &director, int year, int month);
    Video(const std::string &title, int stock, const std::string &director, int year, int month, int day);
    
    
    virtual std::string getGenre() const = 0;
    virtual std::string toString() const = 0;
    virtual void displayMovieInfo() const = 0;
   
    
    std::string getTitle() const;
    std::string getDirector() const;
    int getReleaseYear() const;
    int getReleaseMonth() const;
    int getReleaseDay() const;
    int getStock() const;
    
    void setTitle(const std::string &title);
    void setDirector(const std::string &director);
    void setYear(const int &year);
    void setMonth(const int &month);
    void setDay(const int &day);
    void setStock(const int &stock);
    
    
};

#endif /* video_h */
