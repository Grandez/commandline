#pragma once
#include "make_config.h"
#include "jggtools.hpp"
#include "config_instance.hpp"

using namespace std;
namespace NST {
   class ConfigFactory {
      public:
          static ConfigInstance *getInstance(const char *file, const char *type);
   private:
       ConfigFactory *factory;
       static int getType(Path& path, const char* type);
   };

}
