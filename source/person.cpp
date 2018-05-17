
#include <string>

#include "person.h"

Person::Person(const std::string &first, const std::string &last)
    : firstName(first), lastName(last)
{
}

Person::~Person()
{
}

const std::string &Person::getFirstName() const
{
  return this->firstName;
}

const std::string &Person::getLastName() const
{
  return this->lastName;
}

void Person::setFirstName(const std::string &first)
{
  this->firstName = first;
}

void Person::setLastName(const std::string &last)
{
  this->lastName = last;
}
