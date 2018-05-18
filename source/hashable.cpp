#include "hashable.h"

template <class Type>
Hashable::Hashable()
{

}
template <class Type>
Hashable::~Hashable()
{

}

template <class Type>
const int Hashable::getHash(const std::string& hash) const
{
  size_t sum = 0;
  for (auto i = 0; i < hash.length(); i++)
    sum += (int) hash.at(i);

  return sum;
}

template <class Type>
const int Hashable::getHash(const int& hash) const
{
  return (hash*7 - 121)*2;
}