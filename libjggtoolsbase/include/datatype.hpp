#pragma once
#include <string>
#include "make_config.h"

namespace NSCLP {
   class DataType {
   public:
       virtual std::string toString() = 0;
       virtual char*       toChar(char *buff, size_t size)   = 0;
   };
}
