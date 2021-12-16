#pragma once
#include "make_config.h"
#include "cmdline.hpp"

constexpr auto VERBOSE   = "verbose";
constexpr auto SUMMARY   = "summary";
constexpr auto OVERWRITE = "overwrite";
constexpr auto INPUT     = "input";
constexpr auto OUTPUT    = "output";
constexpr auto CONFIG    = "config";
constexpr auto PATTERN   = "pattern";
constexpr auto EXT       = "ext";

using namespace NSCLP;


#ifdef __MAIN__
 CmdLine *cmdLine = nullptr;
#else 
extern CmdLine *cmdLine;
#endif
