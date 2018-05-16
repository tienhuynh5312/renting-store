//
//  video.cpp
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#include "video.h"
#include <iostream>
#include <fstream>
#include <queue>

Video::Video(){
    
};

Video::Video(const std::string &title, int stock, const std::string &director, int year) : title(title), stock(stock), director(director), date(year,0,0){
    
};

Video::Video(const std::string &title, int stock, const std::string &director, int year, int month) : title(title), stock(stock), director(director), date(year,month,0){
    
};

Video::Video(const std::string &title, int stock, const std::string &director, int year, int month, int day) : title(title), stock(stock), director(director), date(year,month,day){
    
};

void Video::ReadTxtFile(std::string file)
{
    std::ifstream inFile;
    inFile.open(file);
    
    if(inFile.is_open())
    {
        while(!inFile.eof())
        {
//            Transaction Request;
//            inFile >> Request;
//            requestList.push(Request);
        }
        inFile.close();
        return;
    }
    else
    {
        std::cerr<< "Error !! Cannot open the file" << std::endl;
        return;
    }
}
