#pragma once
#include <string>

#include "make_config.h"
#include "datatype.hpp"

using namespace std;

namespace NSCLP {
   class Number : public DataType {
   public:
       long value() { return mValue; }
       virtual string toString() = 0;
       virtual char*  toChar(char *buff, size_t size)   = 0;
       bool operator< (const Number& rhs) { return mValue     < rhs.mValue; }
       bool operator> (const Number& rhs) { return rhs.mValue < mValue;     }
       bool operator<=(const Number& rhs) { return !(*this > rhs);          }
       bool operator>=(const Number& rhs) { return !(*this < rhs);          }
       bool operator==(const Number& rhs) { return   mValue  == rhs.mValue; }
       bool operator!=(const Number& rhs) { return !(mValue  == rhs.mValue);}

       bool operator< (long rhs) { return mValue < rhs;    }
       bool operator> (long rhs) { return rhs < mValue;    }
       bool operator<=(long rhs) { return !(*this > rhs);  }
       bool operator>=(long rhs) { return !(*this < rhs);  }
       bool operator==(long rhs) { return mValue  == rhs;  }
       bool operator!=(long rhs) { return !(*this == rhs); }

   protected:
       int getBase(const char *str);
       long mValue = 0; 
   };
}
