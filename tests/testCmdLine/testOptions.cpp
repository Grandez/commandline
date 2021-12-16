#include "pch.h"
#include "test_config.h"

TEST(Options, no_options) {
  const char *args[] = {"TEST", 0x0};
  CmdLine cmdline(1, args, Parameters());
  unordered_map<string, string> options = cmdline.getDefaultOptions();
  EXPECT_EQ(options.size(), 0);
}
TEST(Options, flags_help) {
  const char *args[] = {"TEST", 0x0};
  Parameters parms = {
     ParmOption("option1")
  }; 
  CmdLine cmdline(1, args, parms);
  Options options = cmdline.getCurrentOptions();
  EXPECT_EQ(options.size(), 1);
}
