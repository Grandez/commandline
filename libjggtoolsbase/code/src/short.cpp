#include <cstdlib>

#include "exceptions.hpp"
#include "msg_locale.hpp"
#include "short.hpp"

#ifdef _WIN32
#pragma warning( disable : 4996 )
#endif
using namespace std;

namespace NSCLP {
   Short::Short() : Integer() {}
   Short::Short(short  value)    : Integer(value) {}
   Short::Short(char   value)    : Integer(value) {}
   Short::Short(string str)      : Integer(str) {
      if (!isShort()) throw new ToolsOutOfRangeException(str, "Short");
   }
   Short::Short(const char *str) : Integer(str) {
      if (!isShort()) throw new ToolsOutOfRangeException(str, "Short");   
   }
   string Short::toString() { return to_string(numberValue); }
   char*  Short::toChar  (char *buff, size_t size) {
        int res = snprintf(buff, size, "%d", (int) numberValue);
        if (res < 0 || res >= size ) throw new ToolsOutOfSpaceException(size);
        return buff;
   }
}
