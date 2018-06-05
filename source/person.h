/**
 * Project#4 : Inventory Tracking System
 * Tien Huynh, Erik Jose Maldonado, Byunggeun Park (BK)
 */

#ifndef _Person_H
#define _Person_H

#include <string>

class Person
{
private:
protected:
  std::string firstName;
  std::string lastName;

public:
  Person(void){};

  /**
   * @brief Create a new persone with name
   * 
   * @param first First name.
   * @param last Last name.
   */
  Person(const std::string &first, const std::string &last);
  ~Person(void);

  /**
   * @brief Get the First Name 
   * 
   * @return const std::string& First name.
   */
  const std::string &getFirstName(void) const;

  /**
   * @brief Get the Last Name
   * 
   * @return const std::string& Last name.
   */
  const std::string &getLastName(void) const;

  /**
   * @brief Set the First Name
   * 
   * @param first First name.
   */
  void setFirstName(const std::string &first);

  /**
   * @brief Set the Last Name
   * 
   * @param last Last name.
   */
  void setLastName(const std::string &last);
};
#endif
