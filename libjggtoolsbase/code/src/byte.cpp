#pragma once
#include <string>
#include <cstddef>

#include "exceptions.hpp"
#include "byte.hpp"

using namespace std;

namespace NSCLP {
   Byte::Byte() { mValue = byte(0x0); }
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
      if (lv == 0 && *pEnd != 0x0)          throw new ToolsOutOfRangeException(str, "Byte");
      if (*pEnd != 0x0)                     throw new ToolsOutOfRangeException(str, "Byte");
      if (lv < -127) throw new ToolsOutOfRangeException(to_string(lv), "Byte");
      if (lv >  255) throw new ToolsOutOfRangeException(to_string(lv), "Byte");
      mValue = (byte) lv;
      numberValue = lv;
   }
   Byte::Byte(char value) {
      this->mValue = byte(value);
      numberValue = value;
   }
   Byte::Byte(long lvalue) {
      if (lvalue < -127) throw new ToolsOutOfRangeException(to_string(lvalue), "Byte");
      if (lvalue >  255) throw new ToolsOutOfRangeException(to_string(lvalue), "Byte");
      mValue = byte(lvalue);
      numberValue = lvalue;
   }
   string Byte::toString() { return to_string((int) mValue); }
   char*  Byte::toChar  (char *buff, size_t size) {
        size_t res = snprintf(buff, size, "%d", (int) mValue);
        if (res < 0 || res >= size ) throw new ToolsOutOfSpaceException(size);
        return buff;
   }
   byte Byte::value() { return mValue; }
}
