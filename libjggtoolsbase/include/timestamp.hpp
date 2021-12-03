/**
* Timestamp inherits from DateTime adding microseconds
*/
#pragma once

#include <vector>
#include <string>

#include "make_config.h"
#include "sstring.hpp"
#include "date.hpp"
#include "time.hpp"
#include "datetime.hpp"

using namespace std;

namespace NST {
   class Timestamp : public DateTime {
   public:
      Timestamp();
      Timestamp(sstring     str);
      Timestamp(const char* str);
      string toString();
      char*  toChar(char *buff, size_t size); 
//      Date   getDate();
//      Time   getTime();
//      struct tm *getTM();
   private:
       static long int uSec;
   };

}
