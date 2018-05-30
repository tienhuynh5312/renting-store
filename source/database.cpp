// #include "database.h"
// #include <regex>
// #include "comedy.h"
// #include "classics.h"
// #include "drama.h"
// #include <iostream>

// bool Database::readTransaction(const std::string &command)
// {
//   std::smatch match;
//   std::regex transPattern(R"((\w)(.*))");
//   std::regex_match(command, match, transPattern);
//   if (match.size() == 0)
//     return false;

//   const std::string &option = match.str(1);
//   if (option == "B")
//   {
//     borrowVideo(command);
//   }
//   else if (option == "R")
//   {
//     // Return
//     returnVideo(command);
//   }
//   else if (option == "I")
//   {
//     // Display Inventory
//     displayInventory();
//   }
//   else if (option == "H")
//   {
//     // Display item of a customer
//     displayCustomerInfo(command);
//   }
//   else
//   {
//     // Invalid option. Notify
//   }
// }

// bool Database::readCustomer(const std::string &command)
// {
//   std::smatch match;
//   std::regex idPattern(R"((\d{4}) (\w+) (\w+))");
//   std::regex_match(command, match, idPattern);
//   if (match.size() != 4)
//     return false;
//   else
//   {
//     int id = std::stoi(match.str(1));
//     std::string first = match.str(2);
//     std::string last = match.str(3);
//     return addCustomer(Customer(first, last, id));
//   }
// }

// bool Database::readVideo(const std::string &command)
// {
//   std::smatch match;
//   std::regex classicsPattern(R"((.+) (\d+) (\d+))");
//   std::regex pattern(R"(([A-Z]), (\d+), (.+), (.+), ([\w| ]+))");
//   std::regex_match(command, match, pattern);

//   if (match.size() != 5)
//     return false;
//   else
//   {
//     int stock = std::stoi(match.str(2));
//     std::string director{match.str(3)};
//     std::string title{match.str(4)};
//     if (match.str(1) == "F")
//     {
//       // Comedy
//       Date year{std::stoi(match.str(5))};
//       return addVideo(Comedy(title, stock, director, year));
//     }
//     else if (match.str(1) == "D")
//     {
//       // Drama
//       Date year{std::stoi(match.str(5))};
//       return addVideo(Drama(title, stock, director, year));
//     }
//     else if (match.str(1) == "C")
//     {
//       // Classics
//       std::smatch last;
//       std::string l{match.str(5)};
//       std::regex lastPart(R"(([\w ]+) (\d) (\d+))");
//       std::regex_match(l, last, lastPart);

//       if (last.size() != 4)
//         return false;
//       else
//       {
//         int month = std::stoi(last.str(2));
//         int year = std::stoi(last.str(3));
//         std::string majorActor{last.str(1)};

//         return addVideo(Classics(title, stock, director, majorActor, Date(year, month)));
//       }
//     }
//     else
//     {
//       return false;
//     }
//   }
// }

// bool Database::borrowVideo(const std::string &command)
// {
//   std::regex pattern(R"((\w) (\d{4}) (\w{1}) (\w{1})(.*))");
//   std::smatch match;
//   std::regex_match(command, match, pattern);

//   if (match.size() <= 5)
//     return false;
//   else
//   {
//     const int customerID = std::stoi(match.str(2));
//     std::string itemType{match.str(3)};
//     std::string videoType{match.str(4)};

//     std::shared_ptr<Customer> borrower = getCustomer(customerID);

//     if (borrower == nullptr)
//       return false;

//     bool borrow = false;
//     if (videoType == "F")
//       borrow = borrowComedy(command);
//     else if (videoType == "D")
//       borrow = borrowDrama(command);
//     else if (videoType == "C")
//       borrow = borrowClassics(command);
//   }
// }

// bool Database::returnVideo(const std::string &command)
// {
//   std::regex pattern(R"( (\d{4}) (\w{1}) (\w{1})(.*))");
//   std::smatch match;
//   std::regex_match(command, match, pattern);
// }

// void Database::displayCustomerInfo(const std::string &command)
// {
//   std::regex pattern(R"((\w) (\d{4})");
//   std::smatch match;
//   std::regex_match(command, match, pattern);

//   if (match.size() != 3)
//     return;
//   else
//   {
//     const int customerID = std::stoi(match.str(2));
//     std::shared_ptr<Customer> borrower = getCustomer(customerID);
//     if (borrower != nullptr)
//     {
//       std::cout << *borrower << std::endl;
//     }
//   }
// }

// void Database::displayInventory()
// {
// }

// bool Database::borrowClassics(const std::string &command)
// {
//   std::regex pattern(R"((\w) (\d{4}) (\w{1}) (\w{1}) (\d*) (\d*) (.*)");
//   std::smatch match;
//   std::regex_match(command, match, pattern);

//   if (match.size() != 8)
//     return false;
//   else
//   {
//     const int month = std::stoi(match.str(5));
//     const int year = std::stoi(match.str(6));

//     const Date date{year, month};
//     std::string majorActor{match.str(7)};
//   }
// }

// bool Database::borrowComedy(const std::string &command)
// {
//   std::regex pattern(R"((\w) (\d{4}) (\w{1}) (\w{1}) ([\w ]*), (\d*))");
//   std::smatch match;
//   std::regex_match(command, match, pattern);

//   if (match.size() != 7)
//     return false;
//   else
//   {
//     const std::string title = match.str(5);
//     const int year = std::stoi(match.str(6));
//     const Date date{year};

//     getVideo(Comedy(title, 0, "", date));
//   }
// }

// bool Database::borrowDrama(const std::string &command)
// {
//   std::regex pattern(R"((\w) (\d{4}) (\w{1}) (\w{1})(.*))");
//   std::smatch match;
//   std::regex_match(command, match, pattern);
// }
