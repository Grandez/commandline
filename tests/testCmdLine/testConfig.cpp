#include "pch.h"
#include "test_config.h"

TEST(Config, no_default) {
  const char *args[] = {"TEST", 0x0};
  Parameters parms = {
     ParmOption("config", Type::CONFIG)
  }; 
  CmdLine cmdline(1, args, parms);
  EXPECT_EQ(1, 1);
}
TEST(Config, default_ini) {
  const char *args[] = {"TEST", 0x0};
  Parameters parms = {
     ParmOption("config", "..\\..\\data\\config_01.ini", Type::CONFIG)
    ,ParmOption("output", "output")
  }; 
  CmdLine cmdline(1, args, parms);
  const char *value = cmdline.getOption("output");
  int res = strcmp(value, "output");
  EXPECT_NE(res, 0);
}
TEST(Config, relaxed) {
  const char *args[] = {"TEST", 0x0};
  Parameters parms = {
     ParmOption("config", "..\\..\\data\\config_relaxed.ini", Type::CONFIG_RELAXED)
    ,ParmOption("output", "output")
  }; 
  CmdLine cmdline(1, args, parms);
  const char *value = cmdline.getOption("output");
  int res = strcmp(value, "output");
  EXPECT_NE(res, 0);
}

