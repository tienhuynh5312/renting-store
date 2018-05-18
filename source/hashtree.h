/**
 * @brief Hash tree
 * 
 * @file Hashtree.h
 * @author Tien Huynh
 * @date 2018-05-18
 */
#ifndef _HASHTREE_H
#define _HASHTREE_H

#include "./binary-search-tree/binarysearchtree.h"

/**
 * @brief Hash tree
 * 
 * @tparam Type Item type for hash tree container.
 */
template <class Type>
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
  HashTree(const size_t& capacity);

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
  virtual bool add(const Type &item);

  /**
   * @brief Remove an item from hash tree.
   * 
   * @param item An item
   * @return true if removal succeeds.
   * @return false if removal failed.
   */
  virtual bool remove(const Type &item);

  /**
   * @brief Find an item in hash tree.
   * 
   * @param item 
   * @return true 
   * @return false 
   */
  virtual Type* contain(const Type &item);

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
  BinarySearchTree<Type>* hashTable;

  /**
   * @brief Total Items are stored in the hash tree.
   * 
   */
  size_t totalItems;

  /**
   * @brief Maximum capaticy of the hash table.
   * 
   */
  size_t hashTableCapacity;

  /**
   * @brief Rebalancing each tree in the hash table.
   * 
   */
  void rebalanceTree();

  /**
   * @brief Get the Hash Index of a item
   * 
   * @param item An Item
   * @return const size_t An index in hash table.
   */
  const size_t getHashIndex(const Type& item);

  const size_t DEFAULT_CAPACITY = 50;
};

#endif // _HASHTREE_H