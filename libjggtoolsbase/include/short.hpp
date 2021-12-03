#pragma once

#include "make_config.h"
#include "type.hpp"
#include "integer.hpp"

using namespace std;

namespace NST {
class Short : public Integer {
public:
   Short();
   Short(string str);
   Short(const char *str);
   Short(char value);
   Short(short lvalue);
   string toString() override;
   char*  toChar  (char *buff, size_t size) override;

private:
   char value;
};
}
