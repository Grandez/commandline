#include "jggtools.hpp"
#include "config_ini.hpp"
#include "config_factory.hpp"
#include "exceptions.hpp"

using namespace std;
namespace NSCLP {
   ConfigInstance *ConfigFactory::getInstance(const char *file, const char *type) {
       Path path(file);
       if (!path.exists()) throw new ToolsNotFoundException(FILE_NOT_FOUND, path.getPath());
       switch(getType(path, type)) {
           case 0: return (ConfigInstance *) new ConfigIni(file);
       }
       return nullptr; 
   }
   int ConfigFactory::getType(Path& path, const char* type) {
       vector<string> configTypes = {"ini;properties"};
       string sep(";");
       string mtype = (type != 0x0 && strlen(type) > 0) ? string(type) : path.getExt();
       for (int i = 0; i < configTypes.size(); i++) {
            sstring str(configTypes[i]);
            vector<string> exts = str.tokenize(sep);
            for (int j = 0; j < exts.size(); j++) {
                 if (exts[j] == mtype) return i;
            }
       } 
       string msg("Configuration files for type ");
       msg.append(mtype).append(" is not implemented");
       throw new ToolsNotSupportedException(msg.c_str());
   }
}

