#include "pch.h"

#include "..\libjggconfig\include\configuration.hpp"

using namespace jggtools;

TEST(ConfigFiles, no_ext) {
  string file("..\\..\\data\\doxyfile");
  string ext("ini");
  int    keys = 217;
  Configuration cfg(file, ext);
  unordered_map<string, set<string>> values = cfg.getConfiguration();
  EXPECT_EQ(values.size(), keys);
}
TEST(ConfigFiles, ini_01) {
  string file("..\\..\\data\\sample01.ini");
  string ext("ini");
  int    keys = 1;
  Configuration cfg(file);
  unordered_map<string, set<string>> values = cfg.getConfiguration();
  EXPECT_EQ(values.size(), keys);
}
