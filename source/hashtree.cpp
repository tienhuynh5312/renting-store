
#ifndef HASH_TREE_CPP
#define HASH_TREE_CPP

#include <list>
#include <memory>

#include "hashtree.h"

template <typename Int, typename HashableType>
HashTree<Int, HashableType>::HashTree()
try : hashTable(new std::list<HashableType>[ DEFAULT_CAPACITY ]), hashTableCapacity(DEFAULT_CAPACITY)
{
}
catch (std::exception &e)
{ // alloc error thrown
}

template <typename Int, typename HashableType>
HashTree<Int, HashableType>::HashTree(const std::size_t &capacity)
try : hashTable(new std::list<HashableType>[ capacity ]), hashTableCapacity(capacity)
{
}
catch (std::exception &e)
{ // alloc error thrown
}

template <typename Int, typename HashableType>
HashTree<Int, HashableType>::~HashTree()
{
  delete[] this->hashTable;
  this->hashTable = nullptr;
}

template <typename Int, typename HashableType>
bool HashTree<Int, HashableType>::add(const Int &key, const HashableType &value)
{
  try
  {
    this->hashTable[key].push_back(value);
    return true;
  }
  catch (std::exception &e)
  {
    return false;
  }
}

template <typename Int, typename HashableType>
bool HashTree<Int, HashableType>::remove(const HashableType &value)
{
  try
  {
    this->hashTable[value->getHash()].remove(*value);
    return true;
  }
  catch (std::exception &e)
  {
    return false;
  }
}

template <typename Int, typename HashableType>
HashableType HashTree<Int, HashableType>::contains(const HashableType &value)
{
  try
  {
    if (this->hashTable[value->getHash()].empty())
      return nullptr;
    else
    { // if hash for value exists return that list
      std::list<HashableType> temp = this->hashTable[value->getHash()];
      // then if the item at **it == item at *value return it
      for (auto it = temp.begin(); it != temp.end(); ++it)
        if (**it == *value)
          return *it;
    }
  }
  catch (std::exception &e)
  {
    return nullptr;
  }
}

#endif
