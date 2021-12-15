#include "pch.h"
#include "test_config.h"

TEST(CmdLine, help_default) {
  const char *args[] = {"TEST", "-h", 0x0};
  EXPECT_THROW(new CmdLine(2, args, Parameters()), HelpSimpleRequested *);
}
TEST(CmdLine, help_long) {
  const char *args[] = {"TEST", "--help", 0x0};
  EXPECT_THROW(new CmdLine(2, args, Parameters()), HelpSimpleRequested *);
}
TEST(CmdLine, help_flag_01) {
  const char *args[] = {"TEST", "+h", 0x0};
  EXPECT_THROW(new CmdLine(2, args, Parameters()), HelpSimpleRequested *);
}
TEST(CmdLine, help_flag_02) {
  const char *args[] = {"TEST", "+he", 0x0};
  EXPECT_THROW(new CmdLine(2, args, Parameters()), HelpSimpleRequested *);
}
TEST(CmdLine, help_flag_03) {
  const char *args[] = {"TEST", "+help", 0x0};
  EXPECT_THROW(new CmdLine(2, args, Parameters()), HelpSimpleRequested *);
}
TEST(CmdLine, help_flag_04) {
  const char *args[] = {"TEST", "+H", 0x0};
  EXPECT_THROW(new CmdLine(2, args, Parameters()), HelpDetailedRequested *);
}
TEST(CmdLine, help_flag_05) {
  const char *args[] = {"TEST", "+HE", 0x0};
  EXPECT_THROW(new CmdLine(2, args, Parameters()), HelpDetailedRequested *);
}
TEST(CmdLine, help_flag_06) {
  const char *args[] = {"TEST", "+HELP", 0x0};
  EXPECT_THROW(new CmdLine(2, args, Parameters()), HelpDetailedRequested *);
}

