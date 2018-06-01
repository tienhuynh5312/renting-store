

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
   * 
   */
  Date();
  /**
   * @brief Destroy the Date object
   * 
   */
  virtual ~Date();
  /**
   * @brief Construct a new Date object
   * 
   * @param date 
   */
  Date(const Date &date);
  /**
   * @brief Construct a new Date object
   * 
   * @param y 
   * @param m 
   * @param d 
   */
  Date(const int &y, const int &m = 1, const int &d = 1);

  /**
   * @brief Get the Year object
   * 
   * @return int 
   */
  int getYear() const;
  /**
   * @brief Get the Month object
   * 
   * @return int 
   */
  int getMonth() const;
  /**
   * @brief Get the Day object
   * 
   * @return int 
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
   * @param rhs 
   * @return true 
   * @return false 
   */
  bool operator<(const Date &rhs) const;
  bool operator>(const Date &rhs) const;
  bool operator==(const Date &rhs) const;
  bool operator!=(const Date &rhs) const;
  bool operator<=(const Date &rhs) const;
  bool operator>=(const Date &rhs) const;

  Date &operator=(const Date &date);
};

#endif /* date_h */
