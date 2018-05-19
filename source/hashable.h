/**
 * @brief 
 * 
 */

#ifndef _HASHABLE_H
#define _HASHABLE_H
#include <string>
/**
 * @brief Provice interface for Hashtree to get unique ID.
 * 
 * @tparam Type Return type of unique ID.
 */
template <class Type>
class Hashable
{
public:
  // Hashable<Type>();
  // virtual ~Hashable<Type>();

  /**
   * @brief Get unique ID of object.
   * 
   * @return Type type unique ID. Number or string are common.
   */
  virtual Type getHash() const = 0;

  /**
   * @brief Get the Hash of a string.
   * 
   * @param hash An string
   * @return Type Hash return type.
   */
  static const int getHash(const std::string& hash);

  /**
   * @brief Get the Hash of a integer.
   * 
   * @param hash An integer.
   * @return Type Hash return type.
   */
  static const int getHash(const int& hash);
};

#endif // !_HASHABLE_H