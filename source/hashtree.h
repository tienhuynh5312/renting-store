/**
 * @brief Hash tree
 * 
 * @file Hashtree.h
 * @author Tien Huynh
 * @date 2018-05-18
 */
#ifndef _HASHTREE_H
#define _HASHTREE_H

#include <list>
#include "hashable.h"

/**
 * @brief Hash tree
 * 
 * @tparam Type Item type for hash tree container.
 */

template <class ItemType>
class HashTree
{
public:
  /**
   * @brief Construct a new Hash Tree object
   * Generate a hash table with capaicy 50.
   */
  HashTree();

  /**
   * @brief Construct a new Hash Tree object with specified capacity.
   * 
   * @param capacity 
   */
  HashTree(const std::size_t& capacity);

  /**
   * @brief Destroy the Hash Tree object
   * Delete every hashTable's binary search tree.
   */
  virtual ~HashTree();

  /**
   * @brief Add an item to hash tree.
   * 
   * @param item An item.
   * @return true if insertion succeeds.
   * @return false if insertion failed.
   */
  virtual bool add(const ItemType &item);

  /**
   * @brief Remove an item from hash tree.
   * 
   * @param item An item
   * @return true if removal succeeds.
   * @return false if removal failed.
   */
  virtual bool remove(const ItemType &item);

  /**
   * @brief Find an item in hash tree.
   * 
   * @param item 
   * @return true 
   * @return false 
   */
  virtual ItemType contains(const ItemType &item);

  /**
   * @brief Optimize the hash tree for better performance.
   * 
   */
  virtual void optimizeHashTree();

private:

  /**
   * @brief An array of binary tree.
   * hashTable = new 
   */
  std::list<ItemType> * hashTable;

  /**
   * @brief Total Items are stored in the hash tree.
   * 
   */
  std::size_t totalItems;

  /**
   * @brief Maximum capaticy of the hash table.
   * 
   */
  std::size_t hashTableCapacity;

  /**
   * @brief Rebalancing each tree in the hash table.
   * 
   */
  void rebalanceTree();

  const std::size_t DEFAULT_CAPACITY = 50;
};

#endif // _HASHTREE_H