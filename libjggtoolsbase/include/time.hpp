#pragma once

#include <vector>
#include <string>

#include "datatype.hpp"

using namespace std;

namespace NSCLP {
class Time : public DataType {
public:
   Time();
   Time(string str);
   Time(const char *str);
   Time(int hour, int min, int sec);
   Time(long lvalue);
   struct tm*  getTM(struct tm*);
   time_t  longValue  (bool full = true);
   int     getHour   ();
   int     getMinutes();
   int     getSeconds();
   string  toString  (const char* fmt = "%X");
   string  toString  () override;
   char*   toChar    (char *buff, size_t size) override;
   char*   format    (char *ptr,  size_t size, const char *fmt);   
private:
    private:
      struct tm mtm;
      time_t lvalue = 0l; 
      void setStructTm();
      void setLongTime();
      void setLongTime(long lvalue);
};
}
