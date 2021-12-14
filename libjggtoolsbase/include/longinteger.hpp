#pragma once

#include "number.hpp"

using namespace std;

namespace NSCLP {
class LongInteger : public Number {
public:
   LongInteger();
   LongInteger(string str);
   LongInteger(const char *str);
   LongInteger(long long lvalue);
   string toString() override;
   char*  toChar  (char *buff, size_t size) override;
protected:
   bool isShort();
   bool isInteger();
};
}
