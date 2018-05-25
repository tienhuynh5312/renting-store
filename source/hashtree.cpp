
#ifndef HASH_TREE_CPP
#define HASH_TREE_CPP

#include <list>
#include <memory>

#include "hashtree.h"

template <typename Int, typename Sptr>
HashTree<Int, Sptr>::HashTree() 
try : hashTable(new std::list<Sptr>[ DEFAULT_CAPACITY ]), hashTableCapacity(DEFAULT_CAPACITY)
{
}
catch (std::exception &e)
{
  // alloc error thrown
}

template <typename Int, typename Sptr>
HashTree<Int, Sptr>::HashTree(const std::size_t &capacity) 
try : hashTable(new std::list<Sptr>[capacity]), hashTableCapacity(capacity)
{
}
catch (std::exception &e)
{
  // alloc error thrown
}

template <typename Int, typename Sptr>
HashTree<Int, Sptr>::~HashTree()
{
  delete[] this->hashTable;
  this->hashTable = nullptr;
}

template <typename Int, typename Sptr>
bool HashTree<Int, Sptr>::add(const Int &key, Sptr itemptr)
{
  try
  {
    this->hashTable[key].push_back(itemptr);
    return true;
  }
  catch (std::exception &e)
  {
    return false;
  }
}

template <typename Int, typename Sptr>
bool HashTree<Int, Sptr>::remove(Sptr itemptr)
{
  try
  {
    this->hashTable[itemptr->getHash()].remove(*itemptr);
    return true;
  }
  catch (std::exception &e)
  {
    return false;
  }
}

template <typename Int, typename Sptr>
Sptr HashTree<Int, Sptr>::contains(Sptr itemptr)
{
  try
  {
    if(this->hashTable[itemptr->getHash()].empty()) return nullptr;
    else 
    { // if hash for itemptr exists return that list
      std::list<Sptr> temp = this->hashTable[itemptr->getHash()];
      // then if the item at **it == item at *itemptr return it
      for(auto it = temp.begin(); it != temp.end(); ++it) 
        if(**it == *itemptr) return *it;
    }
  }
  catch (std::exception &e)
  {
    return nullptr;
  }
}

#endif
