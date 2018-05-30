/**
 * @brief Hash tree
 * 
 * @file Hashtree.h
 * @author Tien Huynh
 * @date 2018-05-18
 */
#ifndef _HASHTREE_H
#define _HASHTREE_H

#include <memory>
#include <vector>

#include "item.h"

/**
 * @brief Hash tree
 * 
 * @tparam Type Item type for hash tree container.
 */

template <class KeyType, class ItemType>
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
  virtual bool add(const KeyType &key, ItemType value);

  /**
   * @brief Remove an item from hash tree.
   * 
   * @param item An item
   * @return true if removal succeeds.
   * @return false if removal failed.
   */
  virtual bool remove(const KeyType &key);

  /**
   * @brief Find an item in hash tree.
   * 
   * @param item 
   * @return true 
   */
<<<<<<< HEAD
  virtual ItemType contains(const KeyType &key);
=======
  virtual HashableType contains(const HashableType &value);

  /**
   * @brief Call a function on every single item in the hashtree
   * 
   * @param function(const HashableType &)
   */
  virtual void foreach(void visit(const HashableType &value));
>>>>>>> 45f7885d4adcfd14bdf483edcd0a1b03f102a051

private:
  /**
   * @brief An array of vector.
   * hashTable = new
   * sperate chaining
   */
<<<<<<< HEAD
  std::list<std::pair<KeyType, ItemType>> *hashTable;
=======
  std::vector<HashableType> []hashTable;
>>>>>>> 45f7885d4adcfd14bdf483edcd0a1b03f102a051

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