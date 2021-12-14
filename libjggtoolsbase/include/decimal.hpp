#pragma once
#include <memory>
#include <string>

#include "make_config.h"
#include "number.hpp"

using namespace std;

namespace NSCLP {
   class Decimal : public Number {
   public:
      Decimal();
      Decimal(string value);
      Decimal(const char* value);
      Decimal(double value);
      Decimal(long value);
      Decimal(long value, int scale);

      string    toStringRounded(int scale = 0);   
      char*     toCharRounded(int scale = 0);   
      float     toFloat();
      double    toDouble();
      long      toFloor();
      long      toCeil();
      long      getIntPart();
      long      getDecPart(); 
      Decimal   round(int scale = 0);
//      const char* format(int scale = -1, int fmt = -1);

      Decimal add     (Decimal& a, Decimal& b);
      Decimal subtract(Decimal& a, Decimal& b);
      Decimal multiply(Decimal& a, Decimal& b);
      Decimal divide  (Decimal& a, Decimal& b);

      Decimal operator+(Decimal&);
      Decimal operator-(Decimal&);
      Decimal operator*(Decimal&);
      Decimal operator/(Decimal&);

      Decimal operator +=(Decimal&);
      Decimal operator -=(Decimal&);
      Decimal operator *=(Decimal&);
      Decimal operator /=(Decimal&);
      Decimal operator +=(long);
      Decimal operator -=(long);
      Decimal operator *=(long);
      Decimal operator /=(long);
      Decimal operator +=(double);
      Decimal operator -=(double);
      Decimal operator *=(double);
      Decimal operator /=(double);

      Decimal operator+(long f);
      Decimal operator+(double f);
      Decimal operator-(long f);
      Decimal operator-(double f);
      Decimal operator*(long f);
      Decimal operator*(double f);
      Decimal operator/(long f);
      Decimal operator/(double f);

      bool operator==(Decimal&) ;
      bool operator!=(Decimal&) ;
      bool operator< (Decimal&) ;
      bool operator<=(Decimal&) ;
      bool operator> (Decimal&) ;
      bool operator>=(Decimal&) ;

      string toString() override;
      char*  toChar  (char *buff, size_t size) override;

   private:
      class DecimalImpl;
      unique_ptr<DecimalImpl, void (*)(DecimalImpl *)> _pdec;
   };

}
