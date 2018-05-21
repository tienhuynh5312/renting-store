#include "hashtree.h"
#include "../source/customer.h"
#include "../source/item.h"
#include "../source/video.h"
#include "../source/transaction.h"
#include <iostream>
template <class ItemType>
HashTree<ItemType>::HashTree()
{
  totalItems = 0;
  hashTableCapacity = DEFAULT_CAPACITY;
  hashTable = new BinarySearchTree<ItemType>[hashTableCapacity]{};
}

template <class ItemType>
HashTree<ItemType>::HashTree(const std::size_t &capacity)
{
  totalItems = 0;
  hashTableCapacity = capacity;
  hashTable = new BinarySearchTree<ItemType>[hashTableCapacity]{};
}

template <class ItemType>
HashTree<ItemType>::~HashTree()
{
  for (std::size_t i = 0; i < hashTableCapacity; i++)
  {
    hashTable[i].clear();
  }

  delete[] hashTable;
}

template <class ItemType>
bool HashTree<ItemType>::add(const ItemType &item)
{
  const int hash = item.getHash();
  const int index = hash % hashTableCapacity;
  return hashTable[index].add(item);
}

template <class ItemType>
bool HashTree<ItemType>::remove(const ItemType &item)
{
  const int hash = item.getHash();
  const int index = hash % hashTableCapacity;
  return true;
}

template <class ItemType>
ItemType HashTree<ItemType>::contains(const ItemType &item)
{
  const int hash = item.getHash();
  const int index = hash % hashTableCapacity;
  auto tmp = hashTable[index].contains(item);
  if (tmp != nullptr)
    return tmp->getItem();
  else
    return ItemType();
}

template <class ItemType>
void HashTree<ItemType>::optimizeHashTree()
{
  rebalanceTree();
}

template <class ItemType>
void HashTree<ItemType>::rebalanceTree()
{
  for (std::size_t i = 0; i < hashTableCapacity; i++)
  {
    hashTable[i].rebalance();
  }
}

template class HashTree<Customer>;
// template class HashTree<Item>;
// template class HashTree<Video>;
// template class HashTree<Transaction>;