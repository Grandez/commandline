#pragma once

#include "make_config.h"
#include "type.hpp"

using namespace std;

namespace NST {
class Natural : Type {
public:
   Natural();
   Natural(string str);
   Natural(const char *str);
   Natural(long lvalue);
   string toString() override;
   char*  toChar  (char *buff, size_t size) override;

private:
   long value;
};
}
