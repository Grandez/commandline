#pragma once

#include "datatype.hpp"

using namespace std;

namespace NSCLP {
class Logical : public DataType {
public:
   Logical();
   Logical(string str);
   Logical(const char *str);
   Logical(char value);
   Logical(long lvalue);
   Logical(bool bvalue);
   bool   value();
   string toString() override;
   char*  toChar  (char *buff, size_t size) override;

private:
   bool mValue = false;
   void setValue(const char *str);
};
}
