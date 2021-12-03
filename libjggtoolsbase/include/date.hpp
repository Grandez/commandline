#pragma once

#include <vector>
#include <string>
#include <memory>

#include "make_config.h"
#include "type.hpp"

using namespace std;

namespace NST {
class Date : public Type {
public:
   Date();
   Date(const Date& src);
   Date(string str);
   Date(const char *str);
   Date(int year, int month, int day);
   Date(time_t lvalue);
   struct tm*  getTM   (struct tm* ptm);
   time_t longValue(bool full = true);
   int getYear();
   int getMonth();
   int getDay();
   int getJulianDay();

   string  toString(const char* fmt = "%F");
   char*   toChar  (char *ptr, size_t size, const char *fmt = "%F"); 
   string  toString() override;
   char*   toChar  (char *buff, size_t size) override;

private:
   class DateBridge;
   unique_ptr<DateBridge, void (*)(DateBridge *)> _dtb;
};
}
