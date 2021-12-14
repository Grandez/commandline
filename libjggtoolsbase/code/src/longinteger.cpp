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
   LongInteger::LongInteger(long long   value)  { this->value = value; }
   LongInteger::LongInteger(string str) : LongInteger(str.c_str()) {}
   LongInteger::LongInteger(const char *str) {
      char * pEnd;
      int base = getBase(str);
      long long lv;
      lv = strtoll (str, &pEnd, base);
      if (lv == LLONG_MAX || lv == LLONG_MIN) throw new ToolsOutOfRangeException(str, "Long Integer");
      if (lv == 0 && *pEnd != 0x0)            throw new ToolsOutOfRangeException(str, "Long Integer");
      if (*pEnd != 0x0)                       throw new ToolsOutOfRangeException(str, "Long Integer");
      value = lv;
   }
   bool LongInteger::isInteger() {
       if (value > UINT_MAX) return false;
       if (value < INT_MIN || value > UINT_MAX) return false;
       return true;
   }
   bool LongInteger::isShort() {
       if (value > USHRT_MAX) return false;
       if (value < SHRT_MIN || value > SHRT_MAX) return false;
       return true;
   }
   string LongInteger::toString() { return to_string(value); }
   char*  LongInteger::toChar  (char *buff, size_t size) {
        int res = snprintf(buff, size, "%lld", value);
        if (res < 0 || res >= size ) throw new ToolsOutOfSpaceException(size);
        return buff;
   }

}
