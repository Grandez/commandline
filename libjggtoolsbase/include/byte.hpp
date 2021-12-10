#pragma once

#include "make_config.h"
#include "datatype.hpp"

using namespace std;

namespace NSCLP {
class Byte : public DataType {
public:
   Byte();
   Byte(string str);
   Byte(const char *str);
   Byte(char value);
   Byte(long lvalue);
   string toString() override;
   char*  toChar  (char *buff, size_t size) override;

private:
   char value;
};
}
