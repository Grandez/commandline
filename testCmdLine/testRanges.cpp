#include "pch.h"
#include "test_config.h"

/*
		ParmRange(const char* name,                     int min, int max) : Parameter(name,            min, max) {};
		ParmRange(const char* name,            int def, int min, int max) : Parameter(name,       def, min, max) {};
		ParmRange(const char* name, Type type, int def, int min, int max) : Parameter(name, type, def, min, max) {};
		ParmRange(const char* name, Type type,          int min, int max) : Parameter(name, type,      min, max) {};
*/
TEST(Ranges, default_valid) {
  const char *args[] = {"TEST", "/range", "0"};
  Parameters parms = {
     ParmRange("range", -1, 1)
  }; 
  CmdLine cmdline(3, args, parms);
  EXPECT_EQ(1, 1);
}
TEST(Ranges, default_invalid_more) {
  const char *args[] = {"TEST", "/range", "2"};
  Parameters parms = {
     ParmRange("range", -1, 1)
  }; 
  EXPECT_THROW(new CmdLine(3, args, parms), CmdLineValueException *);
}
TEST(Ranges, default_invalid_less) {
  const char *args[] = {"TEST", "/range", "-2"};
  Parameters parms = {
     ParmRange("range", -1, 1)
  }; 
  EXPECT_THROW(new CmdLine(3, args, parms), CmdLineValueException *);
}
