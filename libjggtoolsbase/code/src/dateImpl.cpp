#include <ctime>
#include <cstdlib>
#include <cstring>
#include <locale>
#include <regex>
#include <string>
#include <vector>

#include "sstring.hpp"
#include "msg_locale.hpp"
#include "exceptions.hpp"
#include "dateImpl.hpp"

#ifdef _WIN32
#pragma warning( disable : 4996 6385)
#endif

namespace NSCLP {
   DateImpl::DateImpl()      {
      time_t now = time(0);
      memcpy(&mtm, localtime(&now), sizeof(struct tm));
      calculateLongDate(); 
   }
   DateImpl::DateImpl(const char *str, int fmt) : DateImpl() {
      validateDate(str, fmt);
      calculateJulianDay();
      calculateLongDate(); 
   }
   DateImpl::DateImpl(int year, int month, int day) : DateImpl() {
        if (year < 1900)             throw new ToolsValueException(BAD_VALUE, year);
        if (month < 0 || month > 12) throw new ToolsValueException(BAD_VALUE, month);
        if (day   < 0 || day   > 31) throw new ToolsValueException(BAD_VALUE, day);
        if (month != 2 && days[month] < day) throw new ToolsValueException(BAD_VALUE, day);
        if (month == 2) {
            int last = isLeap(year) ? 29 : 28;
            if (day > last) throw new ToolsValueException(BAD_VALUE, day);
        }
        mtm.tm_year = year - 1900;
        mtm.tm_mon  = month - 1;
        mtm.tm_mday = day;
        calculateJulianDay(year, month, day); 
        calculateLongDate(); 
   }
   DateImpl::DateImpl(time_t lvalue) : DateImpl() { 
      this->lvalue = lvalue;
      long2tm(lvalue);
   }
   int DateImpl::getYear      ()   { return mtm.tm_year + 1900; }
   int DateImpl::getMonth     ()   { return mtm.tm_mon  + 1;    }
   int DateImpl::getDay       ()   { return mtm.tm_mday;        }
   int DateImpl::getJulianDay ()   { return mtm.tm_yday;        }

   char* DateImpl::toChar   (char *ptr, size_t size, const char *fmt) {
       format(ptr, size, fmt);
       return ptr;
    }
   string DateImpl::toString   (const char *fmt) {
       char buff[64];
       format(buff, 64, fmt);
       return string(buff);
    }

   char* DateImpl::format   (char* buff, size_t size, const char *fmt) {
        strftime (buff, size, fmt, &mtm);
        return buff;
   }
   struct tm*  DateImpl::getTM(struct tm* ptm)     { 
        memcpy(ptm, &mtm, sizeof(struct tm));
        return ptm;
   }
   time_t       DateImpl::longValue(bool full) { 
       struct tm ttm;
       if (full) return lvalue; 
       memcpy(&ttm, &mtm, sizeof(struct tm));
       ttm.tm_hour = 0;
       ttm.tm_min = 0;
       ttm.tm_sec = 0;
       return mktime(&ttm); 
   }

   void DateImpl::long2tm (time_t amount) {
       int years, leaps, pdays, pending;
       time_t value  = amount;
       int diff = 0;
       do {
          diff++;
          years  = (int) value / 365;
          leaps  = years / 4;
          pdays = (years * 365) + leaps;
          pending = (int) value - pdays;
       } while (pending > 364);

       int jIdx = isLeap(years + 1901) ? 1 : 0;
       int idx = 0;
       while (jdays[jIdx][idx] < pending) idx++;
       mtm.tm_year = years + 1;
       mtm.tm_mon  = idx - 1;
       mtm.tm_mday = pending - (jdays[jIdx][idx - 1]);
       mtm.tm_yday = pending;
    }
    void DateImpl::calculateLongDate() {
      // tm contains year - 1900
      // Since 1900 all leaps years are including 2000
      int leaps = (mtm.tm_year - 1) / 4;
      lvalue = (mtm.tm_year - 1) * 365;
      lvalue += leaps;
      calculateJulianDay(mtm.tm_year + 1900, mtm.tm_mon + 1, mtm.tm_mday);
      lvalue += mtm.tm_yday;
    }
   void DateImpl::calculateJulianDay(int year, int month, int day) {
       int i = isLeap(year) ? 1 : 0;
//       std::vector<int> julian = isLeap(year) ? bdays : jdays;
       month--;
       mtm.tm_yday = (month == 0) ? day : jdays[i][month - 1] + day;
   }
   void DateImpl::calculateJulianDay() { 
        calculateJulianDay(mtm.tm_year + 1900, mtm.tm_mon + 1, mtm.tm_mday); 
   }
   bool  DateImpl::isLeap(int year) {
        if (year < 100) year += 1900; // Control full year or tm year
        if (year % 4)  return false;
		return (year % 400) ? false : true;
	}
	void DateImpl::validateDate      (const char* value, int fmt) {
		time_base::dateorder d;
		vector<int> dt(3);
		regex pat1{ "^[0-9]{1,2}[/-]{1}[0-9]{1,2}[/-]{1}[0-9]{2,4}$" };
		regex pat2{ "^[0-9]{2,4}[/-]{1}[0-9]{1,2}[/-]{1}[0-9]{1,2}$" };
		regex pat;
		d = (fmt == -1) ? use_facet<time_get<char>>(locale()).date_order() 
			            : static_cast<time_base::dateorder>(fmt);

		switch (d) {
        		case time_base::no_order: 
		        case time_base::dmy: 
				case time_base::mdy: pat = pat1; break;
				default:                  pat = pat2;
		}
		bool match = regex_search(value, pat);
		if (!match) throw new ToolsValueException(TXT_VAL_EXPECTED, value, TXT_DATE);
		vector<int> res = sstring(value).tokenizeNumber("[/-]");
		switch (d) {
		       case time_base::dmy: dt = { res[0], res[1], res[2] }; break;
		       case time_base::mdy: dt = { res[1], res[0], res[2] }; break;
		       case time_base::ymd: dt = { res[2], res[1], res[0] }; break;
		       case time_base::ydm: dt = { res[2], res[0], res[1] }; break;
		       default:                  dt = { res[0], res[1], res[2] };
		}
		validateDateValue(value, dt);
        mtm.tm_year = res[0] - 1900;
        mtm.tm_mon  = res[1] - 1;
        mtm.tm_mday = res[2];
	}
	void   DateImpl::validateDateValue (const char *value, vector<int> dt) {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day;

		if (dt[0] < 1 || dt[0] > 31) throw new ToolsValueException(TXT_VAL_INVALID, value);
		if (dt[1] < 1 || dt[1] > 12) throw new ToolsValueException(TXT_VAL_INVALID, value);
		day = days[dt[1]];
        if ((dt[1] == 2) && isLeap(dt[2])) day = 29;
		if (dt[0] > day) throw new ToolsValueException(TXT_VAL_INVALID, value);
	}

}






