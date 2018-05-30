
#ifndef HASH_TREE_CPP
#define HASH_TREE_CPP

#include <memory>
#include <vector>

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
}

template <typename Int, typename HashableType>
bool HashTree<Int, HashableType>::remove(const HashableType &value)
{
}

template <typename Int, typename HashableType>
HashableType HashTree<Int, HashableType>::contains(const HashableType &value)
{
}

template <typename Int, typename HashableType>
bool HashTree<Int, HashableType>::foreach(void visit(const HasableType &value))
{ // begining of hashtree
}

#endif
