#include <cstdlib>

#include "exceptions.hpp"
#include "msg_locale.hpp"
#include "longinteger.hpp"

#ifdef _WIN32
#pragma warning( disable : 4996 )
#endif
using namespace std;

namespace NSCLP {
   LongInteger::LongInteger() {}
   LongInteger::LongInteger(long long   value)  { this->numberValue = value; }
   LongInteger::LongInteger(string str) : LongInteger(str.c_str()) {}
   LongInteger::LongInteger(const char *str) {
      char * pEnd;
      int base = getBase(str);
      long long lv;
      lv = strtoll (str, &pEnd, base);
      if (lv == LLONG_MAX || lv == LLONG_MIN) throw new ToolsOutOfRangeException(str, "Long Integer");
      if (lv == 0 && *pEnd != 0x0)            throw new ToolsOutOfRangeException(str, "Long Integer");
      if (*pEnd != 0x0)                       throw new ToolsOutOfRangeException(str, "Long Integer");
      numberValue = lv;
   }
   bool LongInteger::isInteger() {
       if (numberValue > UINT_MAX) return false;
       if (numberValue < INT_MIN || numberValue > UINT_MAX) return false;
       return true;
   }
   bool LongInteger::isShort() {
       if (numberValue > USHRT_MAX) return false;
       if (numberValue < SHRT_MIN || numberValue > SHRT_MAX) return false;
       return true;
   }
   string LongInteger::toString() { return to_string(numberValue); }
   char*  LongInteger::toChar  (char *buff, size_t size) {
        size_t res = snprintf(buff, size, "%lld", numberValue);
        if (res < 0 || res >= size ) throw new ToolsOutOfSpaceException(size);
        return buff;
   }

}
