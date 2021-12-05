#include <string>
#include <time.h>
#include <regex>

#ifdef _WIN32
#pragma warning( disable : 4996 )
#endif
#include "dateImpl.hpp"
#include "date.hpp"

namespace NST {
   class Date::DateBridge : public DateImpl {
   public:
     DateBridge()                           : DateImpl(){}
     DateBridge(const char *str)            : DateImpl(str) {}
     DateBridge(int year,int month,int day) : DateImpl(year, month, day) {}
     DateBridge(time_t lvalue)              : DateImpl(lvalue) {}
   };
   Date::Date()                : _dtb(new DateBridge(),            [](DateBridge *dtb) { delete dtb; }) {}  
   Date::Date(string str)      : _dtb(new DateBridge(str.c_str()), [](DateBridge *dtb) { delete dtb; }) {}  
   Date::Date(const char *str) : _dtb(new DateBridge(str),         [](DateBridge *dtb) { delete dtb; }) {}  
   Date::Date(time_t lvalue)   : _dtb(new DateBridge(lvalue),      [](DateBridge *dtb) { delete dtb; }) {}
   Date::Date(const Date& t)   : Date(t._dtb->longValue()) {}
   Date::Date(int year,int month,int day) : _dtb(new DateBridge(year, month, day), [](DateBridge *dtb) { delete dtb; }) {}  

   struct tm* Date::getTM   (struct tm* ptm)  { return _dtb->getTM(ptm);     }
   time_t     Date::longValue  (bool full)    { return _dtb->longValue(full);    }
   int        Date::getYear ()                { return _dtb->getYear();      }
   int        Date::getMonth()                { return _dtb->getMonth();     }
   int        Date::getDay  ()                { return _dtb->getDay();       }
   int        Date::getJulianDay ()           { return _dtb->getJulianDay(); }

   string     Date::toString()                         { return _dtb->toString("%F"); }
   char*      Date::toChar  (char *ptr, size_t size)   { return _dtb->toChar(ptr, size, "%F");    }

}
