#include "pch.h"
#include "test_config.h"

TEST(Call, no_args) {
  // Call without arguments
  const char *args[] = {"TEST", 0x0};
  CmdLine cmdline(1, args, Parameters());
  vector<string> inputs = cmdline.getArguments();
  EXPECT_EQ(inputs.size(), 0);
}
TEST(Call, args_1) {
  // Call with 1 argument
  const char *args[] = {"TEST", "arg1", 0x0};
  CmdLine cmdline(2, args, Parameters());
  vector<string> inputs = cmdline.getArguments();
  EXPECT_EQ(inputs.size(), 1);
}
TEST(Call, args_2) {
  // Call with 2 argument
  const char *args[] = {"TEST", "arg1", "arg2", 0x0};
  CmdLine cmdline(3, args, Parameters());
  vector<string> inputs = cmdline.getArguments();
  EXPECT_EQ(inputs.size(), 2);
}
TEST(Call, args_dup) {
  // Call with argument duplicated
  const char *args[] = {"TEST", "arg1", "arg1", 0x0};
  CmdLine cmdline(3, args, Parameters());
  vector<string> inputs = cmdline.getArguments();
  EXPECT_EQ(inputs.size(), 2);
}
TEST(Call, args_invalid) {
  // Call with argument not valid
  const char *args[] = {"TEST", "arg1;arg2", 0x0};
  EXPECT_THROW(CmdLine(2, args, Parameters()), CmdLineParameterException *);
}
TEST(Call, args_quoted) {
  // Call with argument in quoted
  const char *args[] = {"TEST", "'arg1;arg2'", 0x0};
  CmdLine cmdline(2, args, Parameters());
  vector<string> inputs = cmdline.getArguments();
  EXPECT_EQ(inputs.size(), 1);
}
TEST(Call, args_with_spaces) {
  const char *args[] = {"TEST", "'arg1;arg2'", "\"one arg\"", 0x0};
  CmdLine cmdline(3, args, Parameters());
  vector<string> inputs = cmdline.getArguments();
  EXPECT_EQ(inputs.size(), 2);
}
TEST(Call, args_with_flags_00) {
  Parameters parms = {
     ParmFlag("verbose", true)
    ,ParmFlag("echo",    false)
  };
  const char *args[] = {"TEST", "+v", "-e", 0x0};
  CmdLine cmdline(3, args, parms);
  vector<string> inputs = cmdline.getArguments();
  EXPECT_EQ(inputs.size(), 0);
}
TEST(Call, args_with_flags_01) {
  Parameters parms = {
     ParmFlag("verbose", true)
    ,ParmFlag("echo",    false)
  };
  const char *args[] = {"TEST", "arg1", "+v", "-e", 0x0};
  CmdLine cmdline(4, args, parms);
  vector<string> inputs = cmdline.getArguments();
  EXPECT_EQ(inputs.size(), 1);
}
TEST(Call, args_with_flags_02) {
  Parameters parms = {
     ParmFlag("verbose", true)
    ,ParmFlag("echo",    false)
  };
  const char *args[] = {"TEST", "+v", "-e", "arg1", 0x0};
  CmdLine cmdline(4, args, parms);
  vector<string> inputs = cmdline.getArguments();
  EXPECT_EQ(inputs.size(), 1);
}
TEST(Call, args_with_flags_03) {
  Parameters parms = {
     ParmFlag("verbose", true)
    ,ParmFlag("echo",    false)
  };
  const char *args[] = {"TEST", "+v", "arg1", "-e", 0x0};
  CmdLine cmdline(4, args, parms);
  vector<string> inputs = cmdline.getArguments();
  EXPECT_EQ(inputs.size(), 1);
}
TEST(Call, args_with_flags_04) {
  Parameters parms = {
     ParmFlag("verbose", true)
    ,ParmFlag("echo",    false)
  };
  const char *args[] = {"TEST", "arg1", "+v", "arg2", "-e", "arg3", 0x0};
  CmdLine cmdline(6, args, parms);
  vector<string> inputs = cmdline.getArguments();
  EXPECT_EQ(inputs.size(), 3);
}
TEST(Call, args_with_options_00) {
  Parameters parms = {
     ParmOption("option", "value")
  };
  const char *args[] = {"TEST", "arg1", 0x0};
  CmdLine cmdline(2, args, parms);
  vector<string> inputs = cmdline.getArguments();
  EXPECT_EQ(inputs.size(), 1);
}
TEST(Call, args_with_options_01) {
  Parameters parms = {
     ParmOption("option", "value")
  };
  const char *args[] = {"TEST", "arg1", "/o", "val1", 0x0};
  CmdLine cmdline(4, args, parms);
  vector<string> inputs = cmdline.getArguments();
  EXPECT_EQ(inputs.size(), 1);
}
TEST(Call, args_with_options_02) {
  Parameters parms = {
     ParmOption("option", "value")
  };
  const char *args[] = {"TEST", "/o", "val1", "arg1", 0x0};
  CmdLine cmdline(4, args, parms);
  vector<string> inputs = cmdline.getArguments();
  EXPECT_EQ(inputs.size(), 1);
}
TEST(Call, args_error_01) {
  Parameters parms = {
     ParmOption("option", "value")
  };
  const char *args[] = {"TEST", "/o", "/o", "val1", "arg1", 0x0};
  EXPECT_THROW(CmdLine(5, args, parms), CmdLineMissingArgumentException *);
}