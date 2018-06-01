

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
     * @param title 
     * @param stock 
     * @param director 
     */
    Comedy(const std::string &title, int stock, const std::string &director);
    /**
     * @brief Construct a new Comedy object
     * 
     * @param title 
     * @param stock 
     * @param director 
     * @param date 
     */
    Comedy(const std::string &title, int stock, const std::string &director, const Date& date);

    /**
     * @brief Arithematic operation
     * 
     * @param rhs 
     * @return true 
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
     * @brief output stream
     * 
     * @param outStream 
     * @param rhs 
     * @return ostream& 
     */
    friend ostream &operator<<(ostream &outStream, const Comedy &rhs );
};

#endif /* comedy_h */
