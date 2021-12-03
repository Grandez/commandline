#pragma once

#include "make_config.h"
#include "longinteger.hpp"

using namespace std;

namespace NST {
   class Integer : LongInteger {
   public:
      Integer();
      Integer(string str);
      Integer(const char *str);
      Integer(long lvalue);
      string toString() override;
      char*  toChar  (char *buff, size_t size) override;
   protected:
      bool isShort();
      bool isInteger();
      long long value = 0L;
   };
}
