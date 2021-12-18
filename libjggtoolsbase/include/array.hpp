#pragma once

#include "datatype.hpp"

using namespace std;

namespace NSCLP {
class Array : public DataType {
public:
   Array();
   Array(const char *value = 0x0);
   string toString() override;
   char*  toChar  (char *buff, size_t size) override;
};
}
