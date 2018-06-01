

#include <list>
#include <memory>
#include "hashtree.h"
#include "customer.h"
#include "transaction.h"
#include "video.h"

template <class KeyType, class ItemType>
HashTree<KeyType, ItemType>::HashTree()
{
  totalItems = 0;
  hashTable = new std::list<std::pair<KeyType, ItemType>>[DEFAULT_CAPACITY];
  hashTableCapacity = DEFAULT_CAPACITY;
}

template <class KeyType, class ItemType>
HashTree<KeyType, ItemType>::HashTree(const std::size_t &capacity)
{
  totalItems = 0;
  hashTable = new std::list<std::pair<KeyType, ItemType>>[capacity];
  hashTableCapacity = capacity;
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

  const int index = key % hashTableCapacity;
  ItemType v{value};
  this->hashTable[index].push_back(std::make_pair(key, value));
  totalItems++;
  return true;
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
      totalItems--;
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

template <class KeyType, class ItemType>
int HashTree<KeyType, ItemType>::getCapacity() const
{
  return this->hashTableCapacity;
}

template <class KeyType, class ItemType>
std::list<std::pair<KeyType, ItemType>>* HashTree<KeyType, ItemType>::getStructure() const
{
  return this->hashTable;
}

template <class KeyType, class ItemType>
ItemType HashTree<KeyType, ItemType>::operator()(const KeyType& key)
{
  return contains(key);
}

template class HashTree<int, std::shared_ptr<Customer>>;
template class HashTree<int, std::shared_ptr<Transaction>>;
template class HashTree<int, std::shared_ptr<Video>>;
