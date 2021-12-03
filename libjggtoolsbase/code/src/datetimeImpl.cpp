/**
* datetime es la clase base
*  manejamos time_t
*/
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <locale>
#include <regex>
#include <string>

#include "sstring.hpp"
#include "msg_locale.hpp"
#include "exceptions.hpp"
//#include "time.hpp"
#include "datetimeImpl.hpp"

#ifdef _WIN32
#pragma warning( disable : 4996 )
#endif
#include <chrono>

using namespace std;

namespace NST {
   DateTimeImpl::DateTimeImpl()                {
      std::time_t now;
      time(&now);
      memcpy(&mtm, localtime(&now), sizeof(struct tm));
      lvalue = now;
   }
   DateTimeImpl::DateTimeImpl(const char *str) {
      regex pat{ "^[0-9]{4}[/-]{1}[0-9]{1,2}[/-]{1}[0-9]{1,2}[/-]{1}[/- ]{1}[0-9]{1,2}:[0-9]{1,2}:[0-9]{1,2}$" };
	  bool match = regex_search(str, pat);
	  if (!match) throw new ToolsCastException(BAD_DATETIME, str);
	  vector<int> res = sstring(str).tokenizeNumber("[/-:]");
      pDate = new Date(res[0], res[1], res[2]);
      pTime = new Time(res[3], res[4], res[5]);
      fillTM();
   }
   DateTimeImpl::DateTimeImpl(int year, int month, int day, int hour, int minutes, int seconds) : DateTimeImpl() {
        pDate = new Date(year, month, day);
        pTime = new Time(hour, minutes, seconds);
        fillTM();
   }
   DateTimeImpl::DateTimeImpl(time_t lvalue) : DateTimeImpl() { 
       lvalue = lvalue;
       const time_t *tt = &lvalue;
       memcpy(&mtm, localtime(tt), sizeof(struct tm));
   }

   char*  DateTimeImpl::toChar   (char *ptr) { 
          strftime(ptr, 20, "%F %T", &mtm);
          return ptr;
   }
   string DateTimeImpl::toString ()          { 
       char sz[20];
       toChar(sz);
       return string(sz);
   }
 
   int DateTimeImpl::getYear()      { return mtm.tm_year + 1900; }
   int DateTimeImpl::getMonth()     { return mtm.tm_mon  +    1; }
   int DateTimeImpl::getDay()       { return mtm.tm_mday;        }
   int DateTimeImpl::getJulianDay() { return mtm.tm_yday;        }
   int DateTimeImpl::getHour()      { return mtm.tm_hour;        }
   int DateTimeImpl::getMinutes()   { return mtm.tm_min;         }
   int DateTimeImpl::getSeconds()   { return mtm.tm_sec;         }

   struct tm*  DateTimeImpl::getTM() { return &mtm;  }
   time_t      DateTimeImpl::timet() { return lvalue; }
}
