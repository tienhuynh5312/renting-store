/**
 * Project#4 : Inventory Tracking System
 * Tien Huynh, Erik Jose Maldonado, Byunggeun Park (BK)
 */

#ifndef _HASHABLE_H
#define _HASHABLE_H
#include <string>
/**
 * @brief Provice interface for Hashtree to get unique ID.
 * 
 * @tparam Type Return type of unique ID.
 */
class Hashable
{
public:
  // Hashable<Type>();
  // virtual ~Hashable<Type>();
  virtual int getHash() const = 0;
  /**
   * @brief Get the Hash of a string.
   * 
   * @param hash An string
   * @return Type Hash return type.
   */
  static int getHash(const std::string &hash)
  {
    size_t sum = 0;
    for (size_t i = 0; i < hash.length(); i++)
      sum += (int)hash.at(i);

    return sum;
  };

  /**
   * @brief Get the Hash of a integer.
   * 
   * @param hash An integer.
   * @return Type Hash return type.
   */
  static int getHash(const int &hash)
  {
    return (hash * 7 + 121);
  };
};

#endif // !_HASHABLE_H