#include <string>


//#include "configImpl.hpp"
#include "config_factory.hpp"
#include "config_instance.hpp"
#include "configuration.hpp"

using namespace std;

namespace NST {
   class Configuration::ConfigBridge {
   public:
      ConfigBridge(const char *configFile, char *type) {
       ConfigInstance *instance =  ConfigFactory::getInstance(configFile, type);
      }
   private:
      ConfigInstance *instance;
   };

   Configuration::Configuration(string configFile, char *type) : Configuration(configFile.c_str(), type) {}
   Configuration::Configuration(const char *configFile, char *type) : 
                _pcfg(new ConfigBridge(configFile, type), [](ConfigBridge *pcfg) { delete pcfg; }) {}  
}
