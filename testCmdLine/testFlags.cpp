#include "pch.h"
#include "test_config.h"

TEST(Flags, no_flags) {
  const char *args[] = {"TEST", 0x0};
  CmdLine cmdline(1, args);
  Flags flags = cmdline.getDefaultFlags();
  EXPECT_EQ(flags.size(), 0);
}
TEST(Flags, flags_help) {
  const char *args[] = {"TEST", 0x0};
  Parameters parms = {
     ParmFlag("help")
  }; 
  CmdLine cmdline(1, args, parms);
  Flags flags = cmdline.getDefaultFlags();
  EXPECT_EQ(flags.size(), 1);
}
TEST(Flags, flags_01) {
  const char *args[] = {"TEST", 0x0};
  Parameters parms = {
     ParmFlag("verbose", true)
  }; 
  CmdLine cmdline(1, args, parms);
  Flags flags = cmdline.getDefaultFlags();
  EXPECT_EQ(flags.size(), 1);
}
TEST(Flags, flags_02) {
  const char *args[] = {"TEST", 0x0};
  Parameters parms = {
     ParmFlag("verbose", true)
    ,ParmFlag("echo",    false)
  }; 
  CmdLine cmdline(1, args, parms);
  Flags flags = cmdline.getDefaultFlags();
  EXPECT_EQ(flags.size(), 2);
}
TEST(Flags, flags_active) {
  const char *args[] = {"TEST", 0x0};
  Parameters parms = {
     ParmFlag("verbose", true)
    ,ParmFlag("echo",    false)
  }; 
  CmdLine cmdline(1, args, parms);
  EXPECT_TRUE (cmdline.hasFlag("verbose"));
  EXPECT_FALSE(cmdline.hasFlag("echo"));
}
TEST(Flags, flags_letters) {
  const char *args[] = {"TEST", "+abc"};
  Parameters parms = {
     ParmFlag("aflag")
    ,ParmFlag("bflag")
    ,ParmFlag("cflag")
  }; 
  CmdLine cmdline(2, args, parms);
  EXPECT_TRUE (cmdline.hasFlag("aflag"));
  EXPECT_TRUE (cmdline.hasFlag("bflag"));
  EXPECT_TRUE (cmdline.hasFlag("cflag"));
}