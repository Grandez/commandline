#pragma once

#include "make_config.h"
#include "datatype.hpp"

using namespace std;

namespace NST {
class LongInteger : public DataType {
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
   long long value = 0L;
};
}
