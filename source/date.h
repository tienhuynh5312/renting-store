

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
  virtual ~Date();
  Date(const Date &date);
  Date(const int &y, const int &m = 1, const int &d = 1);

  int getYear() const;
  int getMonth() const;
  int getDay() const;

  void setYear(int year);
  void setMonth(int month);
  void setDay(int day);

  bool operator<(const Date &rhs) const;
  bool operator>(const Date &rhs) const;
  bool operator==(const Date &rhs) const;
  bool operator!=(const Date &rhs) const;
  bool operator<=(const Date &rhs) const;
  bool operator>=(const Date &rhs) const;

  Date &operator=(const Date &date);
};

#endif /* date_h */
