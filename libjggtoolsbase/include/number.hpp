#pragma once
#include <string>

#include "make_config.h"
#include "datatype.hpp"

using namespace std;

namespace NSCLP {
   class Number : public DataType {
   public:
       long value() { return (long) numberValue; }
       virtual string toString() = 0;
       virtual char*  toChar(char *buff, size_t size)   = 0;
       bool operator< (const Number& rhs) { return numberValue     < rhs.numberValue; }
       bool operator> (const Number& rhs) { return rhs.numberValue < numberValue;     }
       bool operator<=(const Number& rhs) { return !(*this > rhs);          }
       bool operator>=(const Number& rhs) { return !(*this < rhs);          }
       bool operator==(const Number& rhs) { return   numberValue  == rhs.numberValue; }
       bool operator!=(const Number& rhs) { return !(numberValue  == rhs.numberValue);}

       bool operator< (long rhs) { return numberValue < rhs;    }
       bool operator> (long rhs) { return rhs < numberValue;    }
       bool operator<=(long rhs) { return !(*this > rhs);  }
       bool operator>=(long rhs) { return !(*this < rhs);  }
       bool operator==(long rhs) { return numberValue  == rhs;  }
       bool operator!=(long rhs) { return !(*this == rhs); }

   protected:
       int getBase(const char *str);
       long long numberValue = 0; 
   };
}
