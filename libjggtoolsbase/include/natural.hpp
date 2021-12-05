#pragma once

#include "make_config.h"
#include "datatype.hpp"

using namespace std;

namespace NST {
class Natural : public DataType {
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
