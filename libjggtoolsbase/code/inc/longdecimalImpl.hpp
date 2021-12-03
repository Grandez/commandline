#pragma once

#include "longDecimal.hpp"
#include "longDecimalImpl.hpp"

using namespace std;

namespace NST {
   class LongDecimal::LongDecimalImpl {
   public:
      LongDecimalImpl(string      value);
      LongDecimalImpl(const char* value);
      LongDecimalImpl(float       value);
      LongDecimalImpl(double      value);
      LongDecimalImpl(int value);
      LongDecimalImpl(long value);
      LongDecimalImpl(long value, int scale);
      long    getIntPart();
      long    getDecPart();
      string  toString();
      char*   toChar();
      string toStringRounded(int scale);
      char*   toCharRounded(int scale);
      float   toFloat();
      double  toDouble();
      long    toFloor();
      long    toCeil();
      LongDecimal round(int scale);
      LongDecimal add       (LongDecimal& a, LongDecimal&b);
      LongDecimal subtract  (LongDecimal& a, LongDecimal& b);
      LongDecimal multiply  (LongDecimal& a, LongDecimal& b);
      LongDecimal divide    (LongDecimal& a, LongDecimal& b);
      bool    equal     (LongDecimal& b);
      bool    gt        (LongDecimal& b);
      bool    lt        (LongDecimal& b);
      bool    ge        (LongDecimal& b);
      bool    le        (LongDecimal& b);

   private:
      long double value;
      long scale = 0;
      long number = 0; 
      char buffer[512] = {0x0}; // Common bufffer
      // Store values for binary operations 
      struct opers {
         long number1;
         long number2;
         long scale1;
         long scale2;
      };
      void    adjustScales(struct opers *);
      void    calculateScale(struct opers *);
      void    setValues();  
      string makeString (long long value, int scale);
   };
}