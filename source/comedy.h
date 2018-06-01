

#ifndef comedy_h
#define comedy_h

#include <stdio.h>
#include "video.h"
#include <string>
#include <iostream>

using namespace std;

class Comedy : public Video{
public:
    Comedy(){ videoType = VideoType::COMEDY;};
    virtual ~Comedy();
    
    Comedy(const std::string &title, int stock, const std::string &director);
    Comedy(const std::string &title, int stock, const std::string &director, const Date& date);

    bool operator<(const Comedy & rhs) const;
    bool operator==(const Comedy & rhs) const;


    int getHash() const;
    friend ostream &operator<<(ostream &outStream, const Comedy &rhs );
};

#endif /* comedy_h */
