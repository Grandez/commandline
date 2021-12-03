#pragma once
#include <unordered_map>
#include <set>
#include "make_config.h"

#include "config_instance.hpp" 

namespace NST {
class ConfigIni : public ConfigInstance {
   public:
      ConfigIni(const char *path);
      void loadConfigFile () override;
      void writeConfigFile() override;
      void parseConfigFile() override;

   private:
      char *buffer = 0x0;
};

}