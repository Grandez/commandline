#pragma once
#include "make_config.h"

namespace NSCLP {
	class DataTypes { 
    public:
         static const int CHAR     =  0;
         static const int STRING   =  1;
         static const int BOOL     =  2;
		 static const int BYTE     =  3;
         static const int SHORT    =  4;
         static const int NATURAL  =  5;
         static const int INTEGER  =  6;
         static const int LONG     =  7;
         static const int DECIMAL  =  8;
		 static const int DATE     =  9;
         static const int TIME     = 10;
         static const int DATETIME = 11;
         static const int TMS      = 12;
		 static const int DIR      = 13;
         static const int FILE     = 14;
	};
}