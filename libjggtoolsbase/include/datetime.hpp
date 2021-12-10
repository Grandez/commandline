#pragma once

#include <vector>
#include <string>

using namespace std;

namespace NSCLP {
class DateTime : public Time {
public:
   DateTime();
   DateTime(string str);
   DateTime(const char *str);
   DateTime(int year, int month, int day, int hour, int min, int sec);
   DateTime(time_t lvalue);
   struct tm*  getTM();
   time_t      timet();
   int         getYear     ();
   int         getMonth    ();
   int         getDay      ();
   int         getJulianDay();
   int         getHour     ();
   int         getMinutes  ();
   int         getSeconds  ();

   string toString() override;
   char*  toChar(char *buff, size_t size) override;
protected:
   struct tm mtm;
   long long lvalue = 0l; 
private:
   void fillTM(Date *pDate, Time *pTime);
};
}
