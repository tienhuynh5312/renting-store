
#include <string>

#include "borrowable.h"
#include "classics.h"
#include "comedy.h"
#include "customer.h"
#include "date.h"
#include "drama.h"
#include "person.h"
#include "store.h"
#include "transaction.h"

// test main to make sure it compiles
int main()
{
  Customer me{"Tien","Huynh",1111};
  Transaction a{"Nhung ma"};
  Item book{"book"};
  return 0;
}
