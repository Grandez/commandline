#pragma once

#include "integer.hpp"

using namespace std;

namespace NSCLP {
class Short : public Integer {
public:
   Short();
   Short(string str);
   Short(const char *str);
   Short(char value);
   Short(short lvalue);
   string toString() override;
   char*  toChar  (char *buff, size_t size) override;
};
}
