#include "pch.h"
#include "test_config.h"

TEST(Arguments, no_arguments) {
  const char *args[] = {"TEST", 0x0};
  CmdLine cmdline(1, args);
  EXPECT_EQ(cmdline.getNumArguments(), 0);
}
TEST(Arguments, arguments_1) {
  const char *args[] = {"TEST", "argument"};
  CmdLine cmdline(2, args);
  EXPECT_EQ(cmdline.getNumArguments(), 1);
}
TEST(Arguments, arguments_2) {
  const char *args[] = {"TEST", "argument1", "argument2"};
  CmdLine cmdline(3, args);
  EXPECT_EQ(cmdline.getNumArguments(), 2);
}
TEST(Arguments, arguments_quoted) {
  const char *args[] = {"TEST", "'argument 1'"};
  CmdLine cmdline(2, args);
  EXPECT_EQ(cmdline.getNumArguments(), 1);
}