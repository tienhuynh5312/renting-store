

#ifndef comedy_h
#define comedy_h

#include <stdio.h>
#include "video.h"
#include <string>
#include <iostream>

using namespace std;

class Comedy : public Video{
public:
    /**
     * @brief Construct a new Comedy object
     * 
     */
    Comedy(){ videoType = VideoType::COMEDY;};
    /**
     * @brief Destroy the Comedy object
     * 
     */
    virtual ~Comedy();
    
    /**
     * @brief Construct a new Comedy object
     * 
     * @param title Title if comedy video
     * @param stock Initial stock of comedy video
     * @param director Director of comedy video
     */
    Comedy(const std::string &title, int stock, const std::string &director);
    /**
     * @brief Construct a new Comedy object
     * 
     * @param title Title if comedy video
     * @param stock Initial stock of comedy video
     * @param director director Director of comedy video
     * @param date Date of comedy video
     */
    Comedy(const std::string &title, int stock, const std::string &director, const Date& date);

    /**
     * @brief Arithematic operation
     * 
     * @param rhs Comedy object to compare this object to
     * @return true if this is less than argument
     * @return false 
     */
    bool operator<(const Comedy & rhs) const;
    bool operator==(const Comedy & rhs) const;


    /**
     * @brief Get the Hash object
     * 
     * @return int 
     */
    int getHash() const;
    /**
     * @brief Operator overload that returns an ostream object reference.
     * 
     * @param outStream ostream reference to be returned
     * @param rhs Classics object to send to ostream
     * @return ostream& containing Comedy object data
     */
    friend ostream &operator<<(ostream &outStream, const Comedy &rhs );
};

#endif /* comedy_h */
