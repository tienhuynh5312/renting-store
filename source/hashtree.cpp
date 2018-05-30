
#ifndef HASH_TREE_CPP
#define HASH_TREE_CPP

#include <memory>
<<<<<<< HEAD
#include "customer.h"
=======
#include <vector>
>>>>>>> 45f7885d4adcfd14bdf483edcd0a1b03f102a051

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
bool HashTree<KeyType, ItemType>::add(const KeyType &key, ItemType value)
{
<<<<<<< HEAD

  const int index = key % hashTableCapacity;
  if (contains(key) == nullptr)
  {
    KeyType k = key;
    ItemType v = nullptr;
    std::pair<KeyType, ItemType> item = std::make_pair(k, v);
    this->hashTable[index].push_back(std::move(std::make_pair(k, value)));
    this->hashTable[index].back().second = value;
    return true;
  }
  else
    return false;
=======
}

template <typename Int, typename HashableType>
bool HashTree<Int, HashableType>::remove(const HashableType &value)
{
>>>>>>> 45f7885d4adcfd14bdf483edcd0a1b03f102a051
}

template <class KeyType, class ItemType>
bool HashTree<KeyType, ItemType>::remove(const KeyType &key)
{
<<<<<<< HEAD
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
=======
}

template <typename Int, typename HashableType>
bool HashTree<Int, HashableType>::foreach(void visit(const HasableType &value))
{ // begining of hashtree
>>>>>>> 45f7885d4adcfd14bdf483edcd0a1b03f102a051
}

template class HashTree<int, std::shared_ptr<Customer>>;
#endif
