/**
* A logical value is one of (case insensitive): true, false, yes, no, si, -1, 0, 1
*/
#pragma once

#include <string>

#include "exceptions.hpp"
#include "logical.hpp"

#ifdef _WIN32
#pragma warning( disable : 4996 ) // prev pointer can not be null
#endif

using namespace std;

namespace NSCLP {
   Logical::Logical() { mValue = false; }
   Logical::Logical(string str) : Logical(str.c_str()) {}
   Logical::Logical(const char *str) { setValue(str); }
   Logical::Logical(char value)      { this->mValue = value; }
   Logical::Logical(long lvalue)     { mValue = (lvalue == 0) ? false : true; }
   bool Logical::value()             { 
        return mValue;                          
   } 
   string Logical::toString() { 
       if (mValue) return "true";
       return "false"; 
   }
   char*  Logical::toChar  (char *buff, size_t size) {
       if (size < 5 ) throw new ToolsOutOfSpaceException(size);
       if (mValue)  strcpy(buff, "true");
       if (!mValue) strcpy(buff, "false");
        return buff;
   }
   void Logical::setValue(const char *str) {
      int value = 1;
      if (str == 0x0 ||strlen(str) == 0) {
          this->mValue = false;
          return;
      }
      char *szValue = strdup(str);

      for (size_t i = 0; i < strlen(str); i++) szValue[i] = toupper(szValue[i]);
      if (strcmp(szValue, "TRUE")  == 0) value = -1;
      if (strcmp(szValue, "YES")   == 0) value = -1;
      if (strcmp(szValue, "SI")    == 0) value = -1;
      if (strcmp(szValue, "FALSE") == 0) value =  0;
      if (strcmp(szValue, "NO")    == 0) value =  0;
      if (value != 1) {
          this->mValue = (value == 0) ? false : true;
          free(szValue);
          return;
      }
      int n = atoi(szValue);
      if (n >= -1 && n <= 1 ) {
          this->mValue = (n == 0) ? false : true;
          free(szValue);
          return;
      }
      throw new ToolsValueException(BAD_LOGICAL, szValue);
   }
}
