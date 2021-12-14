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
   LongInteger::LongInteger(long long   value)  { this->mValue = value; }
   LongInteger::LongInteger(string str) : LongInteger(str.c_str()) {}
   LongInteger::LongInteger(const char *str) {
      char * pEnd;
      int base = getBase(str);
      long long lv;
      lv = strtoll (str, &pEnd, base);
      if (lv == LLONG_MAX || lv == LLONG_MIN) throw new ToolsOutOfRangeException(str, "Long Integer");
      if (lv == 0 && *pEnd != 0x0)            throw new ToolsOutOfRangeException(str, "Long Integer");
      if (*pEnd != 0x0)                       throw new ToolsOutOfRangeException(str, "Long Integer");
      mValue = lv;
   }
   bool LongInteger::isInteger() {
       if (mValue > UINT_MAX) return false;
       if (mValue < INT_MIN || mValue > UINT_MAX) return false;
       return true;
   }
   bool LongInteger::isShort() {
       if (mValue > USHRT_MAX) return false;
       if (mValue < SHRT_MIN || mValue > SHRT_MAX) return false;
       return true;
   }
   string LongInteger::toString() { return to_string(mValue); }
   char*  LongInteger::toChar  (char *buff, size_t size) {
        int res = snprintf(buff, size, "%lld", mValue);
        if (res < 0 || res >= size ) throw new ToolsOutOfSpaceException(size);
        return buff;
   }

}
