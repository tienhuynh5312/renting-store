

#ifndef date_h
#define date_h

class Date
{
private:
  int year;
  int month;
  int day;

public:
  /**
   * @brief Construct a new Date object
   */
  Date();
  /**
   * @brief Destroy the Date object
   */
  virtual ~Date();
  /**
   * @brief Construct a new Date object
   * 
   * @param date date object to copy
   */
  Date(const Date &date);
  /**
   * @brief Construct a new Date object
   * 
   * @param y year
   * @param m month
   * @param d day
   */
  Date(const int &y, const int &m = 1, const int &d = 1);

  /**
   * @brief Get the Year object
   * 
   * @return year
   */
  int getYear() const;
  /**
   * @brief Get the Month object
   * 
   * @return month
   */
  int getMonth() const;
  /**
   * @brief Get the Day object
   * 
   * @return day
   */
  int getDay() const;

  /**
   * @brief Set the Year object
   * 
   * @param year 
   */
  void setYear(int year);
  /**
   * @brief Set the Month object
   * 
   * @param month 
   */
  void setMonth(int month);
  /**
   * @brief Set the Day object
   * 
   * @param day 
   */
  void setDay(int day);

  /**
   * @brief Arithematic operation to compare dates
   * 
   * @param rhs object to compare this object 
   * @return true if this is less than argument
   * @return false if this is greater than or equal to argument
   */
  bool operator<(const Date &rhs) const;

  /**
   * @brief Arithematic operation to compare dates
   * 
   * @param rhs object to compare this object 
   * @return true if this is less than argument
   * @return false if this is greater than or equal to argument
   */
  bool operator>(const Date &rhs) const;

  /**
   * @brief Arithematic operation to compare dates
   * 
   * @param rhs object to compare this object 
   * @return true if this is equal to this object
   * @return false if this is not equal to this object
   */
  bool operator==(const Date &rhs) const;

  /**
   * @brief Arithematic operation to compare dates
   * 
   * @param rhs object to compare this object 
   * @return true if this is not equal to this object
   * @return false if this is equal to this object
   */
  bool operator!=(const Date &rhs) const;

  /**
   * @brief Arithematic operation to compare dates
   * 
   * @param rhs object to compare this object 
   * @return true if this is less than or equal to argument
   * @return false if this is greater than argument
   */
  bool operator<=(const Date &rhs) const;

  /**
   * @brief Arithematic operation to compare dates
   * 
   * @param rhs object to compare this object 
   * @return true if this is greater than or equal to argument
   * @return false if this is less than argument
   */
  bool operator>=(const Date &rhs) const;

  /**
   * @brief Construct a copy Date object
   * 
   * @param rhs object to be copied 
   */
  Date &operator=(const Date &date);
};

#endif /* date_h */
