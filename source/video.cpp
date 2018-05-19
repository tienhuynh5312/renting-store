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
  itemType = ItemType::VIDEO;
  this->title = title;
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
  setDate(date);
}

Video::~Video()
{
}

std::string Video::getTitle() const
{
  return title;
}

std::string Video::getDirector() const
{
  return director;
}

const Date &Video::getDate() const
{
  return date;
}

void Video::setTitle(const std::string &title)
{
  this->title = title;
}

void Video::setDirector(const std::string &director)
{
  this->director = director;
}

void Video::setDate(const Date &date)
{
  this->date = date;
}

bool Video::operator<(const Video &rhs) const
{
  if (rhs.videoType != videoType)
    return false;
}

bool Video::operator==(const Video &rhs) const
{
  if (rhs.videoType != videoType)
    return false;
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
