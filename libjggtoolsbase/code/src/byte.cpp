#pragma once

#include <string>

#include "exceptions.hpp"
#include "byte.hpp"

using namespace std;

namespace NST {
   Byte::Byte() { value = 0x0; }
   Byte::Byte(string str) : Byte(str.c_str()) {}
   Byte::Byte(const char *str) {
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
      if (lv == LONG_MAX || lv == LONG_MIN) throw new ToolsOutOfRangeException(str, "Byte");
      if (lv == 0 && pEnd != 0x0)           throw new ToolsOutOfRangeException(str, "Byte");
      if (pEnd != 0x0)                      throw new ToolsOutOfRangeException(str, "Byte");
      if (lv < -127) throw new ToolsOutOfRangeException(to_string(lv), "Byte");
      if (lv >  255) throw new ToolsOutOfRangeException(to_string(lv), "Byte");
      value = (char) lv;
   }
   Byte::Byte(char value) {
      this->value = value;
   }
   Byte::Byte(long lvalue) {
      if (lvalue < -127) throw new ToolsOutOfRangeException(to_string(lvalue), "Byte");
      if (lvalue >  255) throw new ToolsOutOfRangeException(to_string(lvalue), "Byte");
      value = (char) lvalue;
   }
   string Byte::toString() { return to_string(value); }
   char*  Byte::toChar  (char *buff, size_t size) {
        int res = snprintf(buff, size, "%d", value);
        if (res < 0 || res >= size ) throw new ToolsOutOfSpaceException(size);
        return buff;
   }

}
