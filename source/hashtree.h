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
#include <memory>

#include "item.h"

/**
 * @brief Hash tree
 * 
 * @tparam Type Item type for hash tree container.
 */

template <typename Int, typename HashableType>
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
  HashTree(const std::size_t &capacity);

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
  virtual bool add(const Int &key, const HashableType &value);

  /**
   * @brief Remove an item from hash tree.
   * 
   * @param item An item
   * @return true if removal succeeds.
   * @return false if removal failed.
   */
  virtual bool remove(const HashableType &value);

  /**
   * @brief Find an item in hash tree.
   * 
   * @param item 
   * @return true 
   * @return false 
   */
  virtual HashableType contains(const HashableType &value);

  virtual void foreach(void visit(const HashableType &value));

  virtual void reset();

private:
  /**
   * @brief An array of lists.
   * hashTable = new
   * sperate chaining
   */
  std::list<HashableType> *hashTable;

  /**
   * @brief Total Items are stored in the hash tree.
   */
  std::size_t totalItems;

  /**
   * @brief Maximum capaticy of the hash table.
   */
  std::size_t hashTableCapacity;

  // Default size for hashtable
  const std::size_t DEFAULT_CAPACITY = 50;
};

#include "hashtree.cpp"

#endif // _HASHTREE_H