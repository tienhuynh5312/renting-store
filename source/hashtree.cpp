
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
?
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

template <typename Int, typename HashableType>
bool HashTree<Int, HashableType>::foreach(void visit(const HasableType &value))
{ // begining of hashtree
  this->resetPosition();
  auto start = this->position;
  // if  not empty
  if(this->currentListIndex != -1)
  { // do this while at least one value in the hashtree
    do
    {
      visit(*(this->position));
      this->nextPosition();
    } 
    while(start != this->position);
  }// else return false
  else return false;
}

template <typename Int, typename HashableType>
bool HashTree<Int, HashableType>::resetPosition()
{
  for(int i = 0; i < this->hashTableCapacity; ++i)
  {
    if(this->hashTable[i]->empty());
    else 
    { // if hashtree has at least one non empty list
      this->position = this->hashTable[i]->begin();
      this->currentListIndex = i;
      return true;
    }
  }// if hashtree is completely empty set to end
  this->position = this->hashTable[0]->end();
  this->currentListIndex = -1;
  return false;
}

template <typename Int, typename HashableType>
std::list<HashableType>::iterator HashTree<Int, HashableType>::nextPosition()
{
  if(++(this->position) == this->hashTable[currentListIndex]->end())
  {
    for(int i = currentListIndex + 1; i < this->hashTableCapacity and i != this->hashTableCapacity; ++i)
    { // flag to reset if nothing found
      if(this->hashTable[i]->empty()) this->currentListIndex = -1;
      else 
      { // if hashtree has at least one non empty list
        this->position = this->hashTable[i]->begin();
        this->currentListIndex = i;
        return this->position;
      }
    }
    if(this->currentListIndex == -1) this->resetPosition();
    return this->position;
  }
  else return this->position;
}

#endif
