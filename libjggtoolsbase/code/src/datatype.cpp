#include <any>
#include "types.hpp"
#include "datatypelist.hpp"

namespace NSCLP {
   DataType* DataType::createDataType(int type, const char* value)  {
	   switch (type) { 
          case DataTypes::CHAR:       return new Byte       (value);
          case DataTypes::STRING:     return new Array      (value);
          case DataTypes::BOOL:       return new Logical    (value);
          case DataTypes::BYTE:       return new Byte       (value);   
          case DataTypes::SHORT:      return new Byte       (value);
          case DataTypes::NATURAL:    return new Natural    (value);
          case DataTypes::INTEGER:    return new Integer    (value);
          case DataTypes::LONG:       return new LongInteger(value);
          case DataTypes::DECIMAL:    return new Decimal    (value);            
		  case DataTypes::DATE:       return new Date       (value);
		  case DataTypes::TIME:       return new Time       (value);
		  case DataTypes::DATETIME:   return new DateTime   (value);
		  case DataTypes::TMS:        return new Timestamp  (value);
		  case DataTypes::DIR: 
          case DataTypes::FILE:       return new Path       (value);
          default:                    return new NoDataType (value);
       }
   }
}
