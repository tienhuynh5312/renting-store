// #include "database.h"
// #include <regex>
// #include "comedy.h"
// #include "classics.h"
// #include "drama.h"

// bool Database::readTransaction(const std::string &command)
// {
//   std::smatch match;
//   std::regex transPattern(R"((\w)(.*))");
//   std::regex_match(command, match, transPattern);
//   std::cout << match.size() << std::endl;
//   if (match.size() == 0)
//     return false;

//   const std::string &option = match.str(1);
//   if (option == "B")
//   {
//     // Borrow
        // match.str(2) customer iD
        // str(3) media type
        // str(4) movie type 
        // DIFFERENT CASES
        // if Classics
        // str(5) month
        // str(6) year
        // str(7) major Actor
        // else
        // title
        // year
//   }
//   else if (option == "R")
//   {
//     // Return
//     // match.str(2) customer iD
//     // str(3) media type
//     // str(4) movie type
//     // if CLassics
//     // str(5) month
//     // str(6) year
//     // str(7) major Actor
//     // else
//     // title
//     // year
//   }
//   else if (option == "I")
//   {
//     // Display Inventory
//     // using traverse function in Hashtree to display
//    std::cout << "********** Comedy Invectory **********" << std::endl;
//    hashtree.traverse(?)(variable);
//    std::cout << endl;

//    std::cout << "********** Drama Invectory **********" << std::endl;
//    hashtree.traverse(?)(variable);
//    std::cout << endl;

//    std::cout << "********** Classic Invectory **********" << std::endl;
//    hashtree.traverse(?)(variable);
//    std::cout << endl;

//   }
//   else if (option == "H")
//   {
//     // Display item of a customer
//    hashtree *temp = hashtree.search(key?);

//    if (temp == nullptr) {
//    std::cout << "The customer ID: " << key?ID? << " does not exist" << std::endl;
//    return false;
//    }

//    //Printing the history of specific customer
//    temp---> print of history;
//    return true;
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
