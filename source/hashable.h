
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
  Hashable();
  virtual ~Hashable();

  /**
   * @brief Get unique ID of object.
   * 
   * @return Type type unique ID. Number or string are common.
   */
  virtual const Type getHash() const = 0;

  /**
   * @brief Get the Hash of a string.
   * 
   * @param hash An string
   * @return Type Hash return type.
   */
  static const int getHash(const std::string& hash) const;

  /**
   * @brief Get the Hash of a integer.
   * 
   * @param hash An integer.
   * @return Type Hash return type.
   */
  static const int getHash(const int& hash) const;
};

#endif // !_HASHABLE_H