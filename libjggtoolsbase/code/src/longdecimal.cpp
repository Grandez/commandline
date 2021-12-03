#include <regex>

#include "longdecimalImpl.hpp"
#include "longDecimal.hpp"

#ifdef _WIN32
#pragma warning( disable : 4996 )
#endif
using namespace std;

namespace NST {
   LongDecimal::LongDecimal(string      value)     : _LongDecimalImpl(new LongDecimalImpl(value), [](LongDecimalImpl *impl) { delete impl; }) {}
   LongDecimal::LongDecimal(const char* value)     : _LongDecimalImpl(new LongDecimalImpl(value), [](LongDecimalImpl *impl) { delete impl; }) {}
   LongDecimal::LongDecimal(float       value)     : _LongDecimalImpl(new LongDecimalImpl(value), [](LongDecimalImpl *impl) { delete impl; }) {}
   LongDecimal::LongDecimal(double      value)     : _LongDecimalImpl(new LongDecimalImpl(value), [](LongDecimalImpl *impl) { delete impl; }) {}
   LongDecimal::LongDecimal(int         value)     : _LongDecimalImpl(new LongDecimalImpl(value), [](LongDecimalImpl *impl) { delete impl; }) {}
   LongDecimal::LongDecimal(long        value)     : _LongDecimalImpl(new LongDecimalImpl(value), [](LongDecimalImpl *impl) { delete impl; }) {}
   LongDecimal::LongDecimal(long value, int scale) : _LongDecimalImpl(new LongDecimalImpl(value, scale), [](LongDecimalImpl *impl) { delete impl; }) {}
   long LongDecimal::getIntPart() { return _LongDecimalImpl->getIntPart(); } 
   long LongDecimal::getDecPart() { return _LongDecimalImpl->getDecPart(); } 

   string  LongDecimal::toString() { return _LongDecimalImpl->toString(); }
   float   LongDecimal::toFloat () { return _LongDecimalImpl->toFloat(); }
   double  LongDecimal::toDouble() { return _LongDecimalImpl->toDouble(); }
   long    LongDecimal::toFloor () { return _LongDecimalImpl->toFloor(); }
   long    LongDecimal::toCeil  () { return _LongDecimalImpl->toCeil(); }
   char*   LongDecimal::toChar  () { return strdup(this->toString().c_str()); }

   string  LongDecimal::toStringRounded (int scale) { return _LongDecimalImpl->toStringRounded(scale); }
   char*   LongDecimal::toCharRounded   (int scale) { return _LongDecimalImpl->toCharRounded(scale);   }

   LongDecimal LongDecimal::round(int scale) { return _LongDecimalImpl->round(scale);   }
   LongDecimal LongDecimal::operator+  (LongDecimal& b) { return _LongDecimalImpl->add     (*this, b);  }
   LongDecimal LongDecimal::operator+= (LongDecimal& b) { return _LongDecimalImpl->add     (*this, b); }
   LongDecimal LongDecimal::operator-  (LongDecimal& b) { return _LongDecimalImpl->subtract(*this, b); }
   LongDecimal LongDecimal::operator-= (LongDecimal& b) { return _LongDecimalImpl->subtract(*this, b); }
   LongDecimal LongDecimal::operator*  (LongDecimal& b) { return _LongDecimalImpl->multiply(*this, b); }
   LongDecimal LongDecimal::operator*= (LongDecimal& b) { return _LongDecimalImpl->multiply(*this, b); }
   LongDecimal LongDecimal::operator/  (LongDecimal& b) { return _LongDecimalImpl->divide  (*this, b); }
   LongDecimal LongDecimal::operator/= (LongDecimal& b) { return _LongDecimalImpl->divide  (*this, b); }
   LongDecimal LongDecimal::operator +=(long   l) {LongDecimal d(l); return _LongDecimalImpl->add     (*this, d); }
   LongDecimal LongDecimal::operator -=(long   l) {LongDecimal d(l); return _LongDecimalImpl->subtract(*this, d); }
   LongDecimal LongDecimal::operator *=(long   l) {LongDecimal d(l); return _LongDecimalImpl->multiply(*this, d); }
   LongDecimal LongDecimal::operator /=(long   l) {LongDecimal d(l); return _LongDecimalImpl->divide  (*this, d); }
   LongDecimal LongDecimal::operator +=(double v) {LongDecimal d(v); return _LongDecimalImpl->add     (*this, d); }
   LongDecimal LongDecimal::operator -=(double v) {LongDecimal d(v); return _LongDecimalImpl->subtract(*this, d); }
   LongDecimal LongDecimal::operator *=(double v) {LongDecimal d(v); return _LongDecimalImpl->multiply(*this, d); }
   LongDecimal LongDecimal::operator /=(double v) {LongDecimal d(v); return _LongDecimalImpl->divide  (*this, d); }

   LongDecimal LongDecimal::operator+(long   v) { LongDecimal d(v); return _LongDecimalImpl->add     (*this, d); }
   LongDecimal LongDecimal::operator+(double v) { LongDecimal d(v); return _LongDecimalImpl->add     (*this, d); }
   LongDecimal LongDecimal::operator-(long   v) { LongDecimal d(v); return _LongDecimalImpl->subtract(*this, d); }
   LongDecimal LongDecimal::operator-(double v) { LongDecimal d(v); return _LongDecimalImpl->subtract(*this, d); }
   LongDecimal LongDecimal::operator*(long   v) { LongDecimal d(v); return _LongDecimalImpl->multiply(*this, d); }
   LongDecimal LongDecimal::operator*(double v) { LongDecimal d(v); return _LongDecimalImpl->multiply(*this, d); }
   LongDecimal LongDecimal::operator/(long   v) { LongDecimal d(v); return _LongDecimalImpl->divide  (*this, d); }
   LongDecimal LongDecimal::operator/(double v) { LongDecimal d(v); return _LongDecimalImpl->divide  (*this, d); }

   bool LongDecimal::operator==(LongDecimal& b) { return  _LongDecimalImpl->equal(b); }
   bool LongDecimal::operator!=(LongDecimal& b) { return !_LongDecimalImpl->equal(b); }
   bool LongDecimal::operator< (LongDecimal& b) { return  _LongDecimalImpl->lt(b);    }
   bool LongDecimal::operator<=(LongDecimal& b) { return  _LongDecimalImpl->le(b);    }
   bool LongDecimal::operator> (LongDecimal& b) { return  _LongDecimalImpl->gt(b);    }
   bool LongDecimal::operator>=(LongDecimal& b) { return  _LongDecimalImpl->ge(b);    }

   LongDecimal LongDecimal::add     (LongDecimal& a, LongDecimal& b) { return  _LongDecimalImpl->add(a, b);      }
   LongDecimal LongDecimal::subtract(LongDecimal& a, LongDecimal& b) { return  _LongDecimalImpl->subtract(a, b); }
   LongDecimal LongDecimal::multiply(LongDecimal& a, LongDecimal& b) { return  _LongDecimalImpl->multiply(a, b); }
   LongDecimal LongDecimal::divide  (LongDecimal& a, LongDecimal& b) { return  _LongDecimalImpl->divide(a, b);   }
   //TODO Check when number fit in float, double or not

   bool   LongDecimal::isLongDecimal() { 
       if ()
    }
   string LongDecimal::toString() { return to_string(value); }
   char*  LongDecimal::toChar  (char *buff, size_t size) {
        int res = snprintf(buff, size, "%ld", value);
        if (res < 0 || res >= size ) throw new ToolsOutOfSpaceException(size);
        return buff;
   }

}
