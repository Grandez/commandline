#include <string>

#include "config_factory.hpp"
#include "configuration.hpp"

using namespace std;

namespace NSCLP {
   class Configuration::ConfigBridge {
   public:
       ConfigBridge(const char *configFile, const char *type) {
           instance =  ConfigFactory::getInstance(configFile, type);
       }
       unordered_map<string, set<string>> getConfiguration()            { return instance->getPairKeyValues(); }
       set<string>                        getKeyValues(const char *key) { return instance->getKeyValues();     }
   private:
      ConfigInstance *instance = nullptr;
   };

//   Configuration::Configuration(string configFile, string type) : Configuration(configFile.c_str(), type.c_str()) {}
   Configuration::Configuration(string configFile, string type) : 
                _pcfg(new ConfigBridge(configFile.c_str(), type.c_str()), [](ConfigBridge *pcfg) { delete pcfg; }) {}  
   Configuration::Configuration(const char *configFile, char *type) : 
                _pcfg(new ConfigBridge(configFile, type), [](ConfigBridge *pcfg) { delete pcfg; }) {}  

   unordered_map<string, set<string>> Configuration::getConfiguration() { return _pcfg->getConfiguration(); }
   set<string>   Configuration::getValue(string key)                    { return getValue(key.c_str());            }
   set<string>   Configuration::getValue(const char *key)               { return _pcfg->getKeyValues(key);  }
}
