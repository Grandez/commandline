#include "pch.h"

#include "../include/make_config.h"
#include "../libcmdline/include/cmdline_cmdline.hpp"

using namespace NSCLP;

TEST(CmdLine, TestName) {
  const char *args[] = {"TEST", 0x0};
  CmdLine cmdline(1, args);

  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}