#pragma once
#include <cstddef>
#include "make_config.h"
#include "number.hpp"

using namespace std;

namespace NSCLP {
class Byte : public Number {
public:
   Byte();
   Byte(string str);
   Byte(const char *str);
   Byte(char value);
   Byte(long lvalue);
   string toString() override;
   char*  toChar  (char *buff, size_t size) override;
   byte value();
private:
   byte mValue;
};
}
