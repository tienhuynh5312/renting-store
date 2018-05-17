#ifndef _Person_H
#define _Person_H

#include <string>

class Person
{
private:
protected:
  std::string firstName;
  std::string lastName;

public:
  // person needs name
  Person(void) = delete;
  Person(const std::string &first, const std::string &last);
  ~Person(void);
  const std::string &getFirstName(void) const;
  const std::string &getLastName(void) const;
  void setFirstName(const std::string &first);
  void setLastName(const std::string &last);
};
#endif
