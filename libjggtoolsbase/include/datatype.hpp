#pragma once
#include <string>

#include "make_config.h"

using namespace std;

namespace NSCLP {
   class DataType {
   public:
       virtual string toString() = 0;
       virtual char*  toChar(char *buff, size_t size)   = 0;
   protected:
       int getBase(const char *str);
   };
}
