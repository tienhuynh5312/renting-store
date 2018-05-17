#ifndef _Person_H
#define _Person_H

#include <string>

class Person
{
protected:
  std::string firstName;
  std::string lastName;

public:
  Person() = delete; // Do not accept a person without name
  Person(const std::string &first, const std::string &last);
  ~Person();
  std::string &getFirstName() const;
  std::string &getLastName() const;
  void setFirstName(const std::string &last);
  void setLastName(const std::string last);
}
#endif
