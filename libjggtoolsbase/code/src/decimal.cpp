#include <regex>

#include "sstring.hpp"
#include "exceptions.hpp"
#include "msg_locale.hpp"
#include "decimalImpl.hpp"
#include "decimal.hpp"

#ifdef _WIN32
#pragma warning( disable : 4996 4244 )
#endif

namespace NST {
   Decimal::Decimal(string      value)     : _pdec(new DecimalImpl(value), [](DecimalImpl *impl) { delete impl; }) {}
   Decimal::Decimal(const char* value)     : _pdec(new DecimalImpl(value), [](DecimalImpl *impl) { delete impl; }) {}
   Decimal::Decimal(double      value)     : _pdec(new DecimalImpl(value), [](DecimalImpl *impl) { delete impl; }) {}
   Decimal::Decimal(long        value)     : _pdec(new DecimalImpl(value), [](DecimalImpl *impl) { delete impl; }) {}
   Decimal::Decimal(long value, int scale) : _pdec(new DecimalImpl(value, scale), [](DecimalImpl *impl) { delete impl; }) {}
   long Decimal::getIntPart() { return _pdec->getIntPart(); } 
   long Decimal::getDecPart() { return _pdec->getDecPart(); } 

   string  Decimal::toString() { return _pdec->toString(); }
   float   Decimal::toFloat () { return _pdec->toFloat(); }
   double  Decimal::toDouble() { return _pdec->toDouble(); }
   long    Decimal::toFloor () { return _pdec->toFloor(); }
   long    Decimal::toCeil  () { return _pdec->toCeil(); }
   char*   Decimal::toChar  (char *buff, size_t size) { return _pdec->toChar(buff, size); }

   string  Decimal::toStringRounded (int scale) { return _pdec->toStringRounded(scale); }
   char*   Decimal::toCharRounded   (int scale) { return _pdec->toCharRounded(scale);   }

   Decimal Decimal::round(int scale) { return _pdec->round(scale);   }
   Decimal Decimal::operator+  (Decimal& b) { return _pdec->add     (*this, b);  }
   Decimal Decimal::operator+= (Decimal& b) { return _pdec->add     (*this, b); }
   Decimal Decimal::operator-  (Decimal& b) { return _pdec->subtract(*this, b); }
   Decimal Decimal::operator-= (Decimal& b) { return _pdec->subtract(*this, b); }
   Decimal Decimal::operator*  (Decimal& b) { return _pdec->multiply(*this, b); }
   Decimal Decimal::operator*= (Decimal& b) { return _pdec->multiply(*this, b); }
   Decimal Decimal::operator/  (Decimal& b) { return _pdec->divide  (*this, b); }
   Decimal Decimal::operator/= (Decimal& b) { return _pdec->divide  (*this, b); }
   Decimal Decimal::operator +=(long   l) {Decimal d(l); return _pdec->add     (*this, d); }
   Decimal Decimal::operator -=(long   l) {Decimal d(l); return _pdec->subtract(*this, d); }
   Decimal Decimal::operator *=(long   l) {Decimal d(l); return _pdec->multiply(*this, d); }
   Decimal Decimal::operator /=(long   l) {Decimal d(l); return _pdec->divide  (*this, d); }
   Decimal Decimal::operator +=(double v) {Decimal d(v); return _pdec->add     (*this, d); }
   Decimal Decimal::operator -=(double v) {Decimal d(v); return _pdec->subtract(*this, d); }
   Decimal Decimal::operator *=(double v) {Decimal d(v); return _pdec->multiply(*this, d); }
   Decimal Decimal::operator /=(double v) {Decimal d(v); return _pdec->divide  (*this, d); }

   Decimal Decimal::operator+(long   v) { Decimal d(v); return _pdec->add     (*this, d); }
   Decimal Decimal::operator+(double v) { Decimal d(v); return _pdec->add     (*this, d); }
   Decimal Decimal::operator-(long   v) { Decimal d(v); return _pdec->subtract(*this, d); }
   Decimal Decimal::operator-(double v) { Decimal d(v); return _pdec->subtract(*this, d); }
   Decimal Decimal::operator*(long   v) { Decimal d(v); return _pdec->multiply(*this, d); }
   Decimal Decimal::operator*(double v) { Decimal d(v); return _pdec->multiply(*this, d); }
   Decimal Decimal::operator/(long   v) { Decimal d(v); return _pdec->divide  (*this, d); }
   Decimal Decimal::operator/(double v) { Decimal d(v); return _pdec->divide  (*this, d); }

   bool Decimal::operator==(Decimal& b) { return  _pdec->equal(b); }
   bool Decimal::operator!=(Decimal& b) { return !_pdec->equal(b); }
   bool Decimal::operator< (Decimal& b) { return  _pdec->lt(b);    }
   bool Decimal::operator<=(Decimal& b) { return  _pdec->le(b);    }
   bool Decimal::operator> (Decimal& b) { return  _pdec->gt(b);    }
   bool Decimal::operator>=(Decimal& b) { return  _pdec->ge(b);    }

   Decimal Decimal::add     (Decimal& a, Decimal& b) { return  _pdec->add(a, b);      }
   Decimal Decimal::subtract(Decimal& a, Decimal& b) { return  _pdec->subtract(a, b); }
   Decimal Decimal::multiply(Decimal& a, Decimal& b) { return  _pdec->multiply(a, b); }
   Decimal Decimal::divide  (Decimal& a, Decimal& b) { return  _pdec->divide(a, b);   }
   //TODO Check when number fit in float, double or not

}
