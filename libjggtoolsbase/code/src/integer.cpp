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
   string Integer::toString() { return to_string(value); }
   char*  Integer::toChar  (char *buff, size_t size) {
        int res = snprintf(buff, size, "%d", (int) value);
        if (res < 0 || res >= size ) throw new ToolsOutOfSpaceException(size);
        return buff;
   }
}
