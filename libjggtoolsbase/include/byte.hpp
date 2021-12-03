#pragma once

#include "make_config.h"
#include "type.hpp"

using namespace std;

namespace NST {
class Byte : public Type {
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
