//
//  video.cpp
//  Movie
//
//  Created by Byunggeun Park on 5/14/18.
//  Copyright © 2018 Byunggeun Park. All rights reserved.
//

#include "video.h"

Video::Video(const std::string &title) : Item("Video")
{
    date = Date();
}

Video::Video(const std::string &title, const std::string &director) : Video(title)
{
    this->director = director;
}

Video::Video(const std::string &title, int stock, const std::string &director) : Video(title, director)
{
    setTotalSupply(stock);
}

Video::Video(const std::string &title, int stock, const std::string &director, const Date &date) : Video(title, stock, director)
{
    this->date = date;
}

Video::~Video()
{
}

// void Video::ReadTxtFile(std::string file)
// {
//     std::ifstream inFile;
//     inFile.open(file);

//     if (inFile.is_open())
//     {
//         while (!inFile.eof())
//         {
//             //            Transaction Request;
//             //            inFile >> Request;
//             //            requestList.push(Request);
//         }
//         inFile.close();
//         return;
//     }
//     else
//     {
//         std::cerr << "Error !! Cannot open the file" << std::endl;
//         return;
//     }
// }
