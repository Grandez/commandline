/**
* A ficticious type
*/
#pragma once

#include <string>
#include "nodatatype.hpp"

#ifdef _WIN32
#pragma warning( disable : 4996)
#endif

using namespace std;

namespace NSCLP {
   NoDataType::NoDataType() { }
   NoDataType::NoDataType(const char *value) { 
       if (value != 0x0) mValue = strdup(value);
   }
   NoDataType::~NoDataType()     { if (mValue != 0x0) free(mValue); }
   string NoDataType::toString() { return string(mValue); } 
   char*  NoDataType::toChar  (char *buff, size_t size) {
        *buff = 0x0;
        if (mValue != 0x0) strncpy(buff, mValue, size);
        return buff;
   }
}
