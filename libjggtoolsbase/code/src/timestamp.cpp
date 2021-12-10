#include <time.h>

#ifdef _WIN32
   #include "sys/timeb.h"
#else
   #include <sys/time.h>
#endif

#ifdef _WIN32
#pragma warning( disable : 4996 )
#endif

#include "exceptions.hpp"
#include "timestamp.hpp"

namespace NSCLP {
   Timestamp::Timestamp() : DateTime() {
      //Timestamp::uSec++;
#ifndef _WIN32
      struct timeval mTimeval;
      gettimeofday (&mTimeval, NULL);
      uSec = mtimeVal.tv_usec
#endif
   }
   Timestamp::Timestamp(sstring     str) : DateTime(str) { 
//Timestamp::uSec++; 
}
   Timestamp::Timestamp(const char* str) : DateTime(str) { 
//Timestamp::uSec++; 
}
   string Timestamp::toString() {
      char fmt[] = "%04d-%02d-%02d-%02d:%02d:%02d.06d";
      char buff[30];  
      sprintf(buff, fmt, mtm.tm_year + 1900, mtm.tm_mon + 1, mtm.tm_mday, mtm.tm_hour, mtm.tm_mon, mtm.tm_sec, Timestamp::uSec);
      return string(buff);
   }
   char*  Timestamp::toChar(char *buff, size_t size) {
      char fmt[] = "%04d-%02d-%02d-%02d:%02d:%02d.%06d";
      if (size < 28) throw new ToolsOutOfSpaceException(size);
      sprintf(buff, fmt, mtm.tm_year + 1900, mtm.tm_mon + 1, mtm.tm_mday, mtm.tm_hour, mtm.tm_mon, mtm.tm_sec, Timestamp::uSec);
      return buff;
   }
}
