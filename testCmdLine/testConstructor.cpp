#include "pch.h"

#include "test_config.h"



TEST(CmdLine, TestName) {
  const char *args[] = {"TEST", 0x0};
  CmdLine cmdline(1, args);

  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}