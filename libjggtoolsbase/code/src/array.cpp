// Utility to manage all data types
#pragma once

#include <string>
#include "array.hpp"

#ifdef _WIN32
#pragma warning( disable : 4996)
#endif

using namespace std;

namespace NSCLP {
   Array::Array() { }
   Array::Array(const char *value) {
      if (value != 0x0) mValue = string(value);
   }
   string Array::toString() { return mValue; } 
   char*  Array::toChar  (char *buff, size_t size) {
        *buff = 0x0;
        if (mValue.length() > 0) strncpy(buff, mValue.c_str(), size);
        return buff;
   }
}
