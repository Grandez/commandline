#pragma once

#include "datatype.hpp"

using namespace std;

namespace NSCLP {
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
