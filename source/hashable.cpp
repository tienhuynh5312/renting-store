#include "hashable.h"

// template <class Type>
// Hashable<Type>::Hashable()
// {

// }
// template <class Type>
// Hashable<Type>::~Hashable()
// {

// }

template <class Type>
const int Hashable<Type>::getHash(const std::string& hash)
{
  size_t sum = 0;
  for (auto i = 0; i < hash.length(); i++)
    sum += (int) hash.at(i);

  return sum;
}

template <class Type>
const int Hashable<Type>::getHash(const int& hash)
{
  return (hash*7 - 121)*2;
}