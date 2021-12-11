#include "pch.h"

#include "test_config.h"
#include "../libcmdline/code/inc/cmdlineImplTools.hpp"

TEST(Tools, Turing_01) {
  CmdLineImplTools tools;
  vector<string> tokens = tools.splitParameter("parm1");
  EXPECT_EQ(tokens.size(), 1);
}
TEST(Tools, Turing_02) {
  CmdLineImplTools tools;
  vector<string> tokens = tools.splitParameter("parm1;parm2");
  EXPECT_EQ(tokens.size(), 2);
}
TEST(Tools, Turing_03) {
  CmdLineImplTools tools;
  vector<string> tokens = tools.splitParameter("'parm1;parm2'");
  EXPECT_EQ(tokens.size(), 1);
}
TEST(Tools, Turing_04) {
  CmdLineImplTools tools;
  EXPECT_THROW(tools.splitParameter("'parm1;parm2' "), CmdLineValueException *);
}