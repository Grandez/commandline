#pragma once
#include <vector>
#include <set>
#include <unordered_map>

#include "make_config.h"
#include "jggtools.hpp"

using namespace std;
namespace NSCLP {
   class ConfigInstance {
   public:
      unordered_map<string, set<string>>& getPairKeyValues();
      set<string>                         getKeyValues();
      virtual void loadConfigFile() = 0;
      virtual void writeConfigFile() = 0;
      virtual void parseConfigFile() = 0;
   protected:
      string path;
      vector<sstring> lines;
      unordered_map<string, set<string>> values;
   };
}