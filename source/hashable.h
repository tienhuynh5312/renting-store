
#ifndef _HASHABLE_H
#define _HASHABLE_H

/**
 * @brief Provice interface for Hashtree to get unique ID.
 * 
 * @tparam Type Return type of unique ID.
 */
template <class Type>
class Hashable
{
public:
  /**
   * @brief Get unique ID of object.
   * 
   * @return Type type unique ID. Number or string are common.
   */
  virtual Type getHash() const = 0;
};

#endif // !_HASHABLE_H