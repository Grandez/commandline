#include <string>
#include <time.h>
#include <regex>

#ifdef _WIN32
#pragma warning( disable : 4996 )
#endif
#include "sstring.hpp"
#include "exceptions.hpp"
#include "time.hpp"

namespace NSCLP {
   Time::Time()  {
      time_t now = time(0);
      memcpy(&mtm, localtime(&now), sizeof(struct tm));
      setLongTime();
   }
   Time::Time(string str)      : Time() { if (str.length() > 0) parseString(str); }
   Time::Time(const char *str) : Time() {
      if (str == 0x0) return;
      parseString(string(str));
   }
   Time::Time(long lvalue) { setLongTime(lvalue); }
   Time::Time(int hour, int minutes, int seconds) {
        if (hour < 0    || hour > 23)    throw new ToolsValueException(BAD_VALUE, hour);
        if (minutes < 0 || minutes > 59) throw new ToolsValueException(BAD_VALUE, minutes);
        if (seconds < 0 || seconds > 59) throw new ToolsValueException(BAD_VALUE, seconds);
        lvalue  = ((long) hour * 3600) ;
        lvalue += ((long) minutes * 60);
        lvalue += seconds;
        setStructTm();
   }
   int Time::getHour()     { return mtm.tm_hour;    }
   int Time::getMinutes()  { return mtm.tm_min; }
   int Time::getSeconds()  { return mtm.tm_sec; }

   string     Time::toString(const char* fmt) {
       char szTime[64];
       format(szTime, 64, fmt);  
       return string(szTime);
   }
   string Time::toString()                        { return toString("%X"); }
   char*  Time::toChar  (char *buff, size_t size) { return format(buff, size, "%X"); }

   char*      Time::format  (char *ptr, size_t size, const char *fmt)       { 
        size_t res = strftime(ptr, size, fmt, &mtm); 
        return ptr;
   }
   struct tm* Time::getTM   (struct tm* ptm)  { 
      memcpy(ptm, &mtm, sizeof(struct tm));
      return ptm;
   }
   time_t   Time::longValue  (bool full)  { 
       if (full) return lvalue;
       long val = (mtm.tm_hour * 3600);
       val += (mtm.tm_min * 60);
       val += mtm.tm_sec;
       return  val;
   }
    void Time::setStructTm() {
       mtm.tm_hour = (int) lvalue / 3600;
       long rem = lvalue % 3600;
       mtm.tm_min = rem / 60;
       mtm.tm_sec = rem % 60;
    }
    void Time::setLongTime(long lvalue) {
       this->lvalue = lvalue % 86400;
    }
    void Time::setLongTime() {
        lvalue  = ((long) mtm.tm_hour * 3600l);
        lvalue += (mtm.tm_min * 60l) + mtm.tm_sec;
    }
    void Time::parseString(string str) {
        regex pat{ "^[0-9]{1,2}:[0-9]{1,2}:[0-9]{1,2}$" };
	    bool match = regex_search(str, pat);
	    if (!match) throw new ToolsCastException(BAD_TIME, str);
	    vector<int> res = sstring(str).tokenizeNumber(":");
	    if (res[0] < 0 || res[0] > 23) throw new ToolsCastException(BAD_TIME, str);
	    for (int i = 1; i < 3; i++) {
		    if (res[i] < 0 || res[i] > 59) throw new ToolsCastException(BAD_TIME, str);
        }
        lvalue  = ((long) res[0] * 3600l);
        lvalue += (res[1] * 60l) + res[2];
        setStructTm();
    }
}
