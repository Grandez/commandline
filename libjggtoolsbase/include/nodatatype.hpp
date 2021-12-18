#pragma once

#include "datatype.hpp"

using namespace std;

namespace NSCLP {
class NoDataType : public DataType {
public:
   NoDataType();
   NoDataType(const char *value = 0x0);
   ~NoDataType();
   string toString() override;
   char*  toChar  (char *buff, size_t size) override;
private:
   char *mValue = 0x0;
};
}
