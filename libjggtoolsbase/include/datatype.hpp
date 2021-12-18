#pragma once
#include <any>
#include <string>
#include "types.hpp"

using namespace std;
namespace NSCLP {
   class DataType {
   public:
       virtual string   toString() = 0;
       virtual char*    toChar(char *buff, size_t size)   = 0;
       static DataType* createDataType(int type, const char *value = 0x0);
   };
}
