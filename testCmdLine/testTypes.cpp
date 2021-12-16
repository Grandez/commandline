/*
*/
#include "pch.h"
#include "test_config.h"

// CHAR

// STRING 

// BOOL

// BYTE

// SHORT

// NATURAL

TEST(Natural, default_valid) {
  const char *args[] = {"TEST", "/parm", "0"};
  Parameters parms = {
     ParmOption("parm", Type::NATURAL)
  }; 
  CmdLine cmdline(3, args, parms);
  EXPECT_EQ(1, 1);
}

// INTEGER

// LONG

// DECIMAL

// DATE

// TIME

// DATETIME

// TMS

// DIR

// DIR_EXISTS

// FILE

// FILE_EXISTS



