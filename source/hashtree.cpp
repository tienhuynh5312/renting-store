
#ifndef HASH_TREE_CPP
#define HASH_TREE_CPP

#include <list>
#include <memory>
#include "customer.h"

#include "hashtree.h"

template <class KeyType, class ItemType>
HashTree<KeyType, ItemType>::HashTree() try : hashTable(new std::list<std::pair<KeyType, ItemType>>[ DEFAULT_CAPACITY ]), hashTableCapacity(DEFAULT_CAPACITY)
{
}
catch (std::exception &e)
{ // alloc error thrown
}

template <class KeyType, class ItemType>
HashTree<KeyType, ItemType>::HashTree(const std::size_t &capacity) try : hashTable(new std::list<std::pair<KeyType, ItemType>>[ capacity ]), hashTableCapacity(capacity)
{
}
catch (std::exception &e)
{ // alloc error thrown
}

template <class KeyType, class ItemType>
HashTree<KeyType, ItemType>::~HashTree()
{
  delete[] this->hashTable;
  this->hashTable = nullptr;
}

template <class KeyType, class ItemType>
bool HashTree<KeyType, ItemType>::add(const KeyType &key, const ItemType &value)
{

  const int index = key % hashTableCapacity;
  if (contains(key) == nullptr)
  {
    this->hashTable[index].push_back(std::make_pair<KeyType, ItemType>(key, value));
    return true;
  }
  else
    return false;
}

template <class KeyType, class ItemType>
bool HashTree<KeyType, ItemType>::remove(const KeyType &key)
{
  const int index = key % hashTableCapacity;
  for (auto i = hashTable[index].begin(); i != hashTable[index].end(); i++)
  {
    if (i->first == key)
    {
      hashTable[index].erase(i);
      return true;
    }
  }
  return false;
}

template <class KeyType, class ItemType>
ItemType HashTree<KeyType, ItemType>::contains(const KeyType &key)
{
  const int index = key % hashTableCapacity;
  for (auto i = hashTable[index].begin(); i != hashTable[index].end(); i++)
  {
    if (i->first == key)
    {
      return i->second;
    }
  }
  return nullptr;
}

template class HashTree<int, std::shared_ptr<Customer>>;
#endif
