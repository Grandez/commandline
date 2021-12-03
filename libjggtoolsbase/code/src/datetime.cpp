#include <string>
#include <time.h>
#include <regex>
#include <ctime>

#ifdef _WIN32
#pragma warning( disable : 4996 )
#endif

#include "exceptions.hpp"
#include "sstring.hpp"
#include "date.hpp"
#include "time.hpp"
#include "datetime.hpp"

using namespace std;

namespace NST {
   DateTime::DateTime()                {
      std::time_t now;
      time(&now);
      memcpy(&mtm, localtime(&now), sizeof(struct tm));
      lvalue = now;
   }
   DateTime::DateTime(const char *str) {
      regex pat{ "^[0-9]{4}[/-]{1}[0-9]{1,2}[/-]{1}[0-9]{1,2}[/-]{1}[/- ]{1}[0-9]{1,2}:[0-9]{1,2}:[0-9]{1,2}$" };
	  bool match = regex_search(str, pat);
	  if (!match) throw new ToolsCastException(BAD_DATETIME, str);
	  vector<int> res = sstring(str).tokenizeNumber("[/-:]");
      Date *pDate = new Date(res[0], res[1], res[2]);
      Time *pTime = new Time(res[3], res[4], res[5]);
      fillTM(pDate, pTime);
   }
   DateTime::DateTime(string str) : DateTime(str.c_str()) {}
   DateTime::DateTime(int year, int month, int day, int hour, int minutes, int seconds) : DateTime() {
        Date *pDate = new Date(year, month, day);
        Time *pTime = new Time(hour, minutes, seconds);
        fillTM(pDate, pTime);
   }
   DateTime::DateTime(time_t lvalue) : DateTime() { 
       lvalue = lvalue;
       const time_t *tt = &lvalue;
       memcpy(&mtm, localtime(tt), sizeof(struct tm));
   }

   int DateTime::getYear()      { return mtm.tm_year + 1900; }
   int DateTime::getMonth()     { return mtm.tm_mon  +    1; }
   int DateTime::getDay()       { return mtm.tm_mday;        }
   int DateTime::getJulianDay() { return mtm.tm_yday;        }
   int DateTime::getHour()      { return mtm.tm_hour;        }
   int DateTime::getMinutes()   { return mtm.tm_min;         }
   int DateTime::getSeconds()   { return mtm.tm_sec;         }

   struct tm*  DateTime::getTM() { return &mtm;  }
   time_t      DateTime::timet() { return lvalue; }
   void DateTime::fillTM(Date *pDate, Time *pTime) {
      time_t value = pDate->longValue(false);
      value += pTime->getHour() * 3600;
      value += pTime->getMinutes() * 60;
      value += pTime->getSeconds();
      memcpy(&mtm, localtime(&value), sizeof(struct tm));
    }
   string DateTime::toString() {
      char fmt[] = "%04d-%02d-%02d-%02d:%02d:%02d";
      char buff[22];  
      sprintf(buff, fmt, mtm.tm_year + 1900, mtm.tm_mon + 1, mtm.tm_mday, mtm.tm_hour, mtm.tm_mon, mtm.tm_sec);
      return string(buff);
   }
   char*  DateTime::toChar(char *buff, size_t size) {
      char fmt[] = "%04d-%02d-%02d-%02d:%02d:%02d";
      if (size < 22) throw new ToolsOutOfSpaceException(size);
      sprintf(buff, fmt, mtm.tm_year + 1900, mtm.tm_mon + 1, mtm.tm_mday, mtm.tm_hour, mtm.tm_mon, mtm.tm_sec);
      return buff;
   }
}