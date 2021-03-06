#include <cstdlib>

#include "exceptions.hpp"
#include "msg_locale.hpp"
#include "integer.hpp"

#ifdef _WIN32
#pragma warning( disable : 4996 )
#endif
using namespace std;

namespace NSCLP {
   Integer::Integer() : LongInteger() {}
   Integer::Integer(long  value)    : LongInteger(value) {}
   Integer::Integer(string str)     : LongInteger(str) {
      if (!LongInteger::isInteger()) throw new ToolsOutOfRangeException(str, "Integer");
   }
   Integer::Integer(const char *str) : LongInteger(str) {
      if (!LongInteger::isInteger()) throw new ToolsOutOfRangeException(str, "Integer");   
   }
   string Integer::toString() { return to_string(numberValue); }
   char*  Integer::toChar  (char *buff, size_t size) {
        size_t res = snprintf(buff, size, "%d", (int) numberValue);
        if (res < 0 || res >= size ) throw new ToolsOutOfSpaceException(size);
        return buff;
   }
   bool Integer::isShort()   { return LongInteger::isShort();   }
   bool Integer::isInteger() { return LongInteger::isInteger(); }
}
