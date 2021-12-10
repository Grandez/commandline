#pragma once

#include <string>

#include "exceptions.hpp"
#include "Natural.hpp"

using namespace std;

namespace NSCLP {
   Natural::Natural() { value = 0x0; }
   Natural::Natural(string str) : Natural(str.c_str()) {}
   Natural::Natural(const char *str) {
      char * pEnd;
      char prfx[3];
      int base = 10;
      if (strlen(str) > 2) {
         prfx[0] = str[0];
         prfx[1] = toupper(str[1]);
         prfx[2] = 0x0;
         if (strcmp(prfx, "0X") == 0) base = 16;
      }  
      long int lv;
      lv = strtol (str, &pEnd, base);
      if (lv == LONG_MAX || lv == LONG_MIN) throw new ToolsOutOfRangeException(str, "Natural");
      if (lv == 0 && pEnd != 0x0)           throw new ToolsOutOfRangeException(str, "Natural");
      if (pEnd != 0x0)                      throw new ToolsOutOfRangeException(str, "Natural");
      if (lv < 0)                           throw new ToolsOutOfRangeException(str, "Natural"); 
      value = lv;
   }
   Natural::Natural(long lvalue) {
      this->value = lvalue;
   }
   string Natural::toString() { return to_string(value); }
   char*  Natural::toChar  (char *buff, size_t size) {
        int res = snprintf(buff, size, "%d", value);
        if (res < 0 || res >= size ) throw new ToolsOutOfSpaceException(size);
        return buff;
   }

}
