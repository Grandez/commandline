#pragma once
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <memory>

#include "make_config.h"

using namespace std;
namespace NST {
   class Configuration {
      public:
          Configuration() = delete;
          Configuration(string      configFile, string type = "");
          Configuration(const char *configFile, char *type = 0x0);
          unordered_map<string, set<string>> getConfiguration();
          set<string>                             getValue(string key);
          set<string>                             getValue(const char *key);
   private:
       class ConfigBridge;
       unique_ptr<ConfigBridge, void (*)(ConfigBridge *)> _pcfg;
   };

}
